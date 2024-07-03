#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define num_layers 3
#define num_nodes 19717
#define learning_rate 0.0001
#define num_epochs 100
#define num_features 500
#define num_inputs 10
#define num_outputs 1
#define num_classes 3
#define num_edges 88489

const float beta_1 = 0.9;
const float beta_2 = 0.999;
const float epsilon = 1e-8;

typedef struct Network{
    int labels;
    float **features;
} Network;

typedef struct GNN{
	int neuron;
	float *bias;
	float *delta;
	float **weight;
	float **momentumW;
	float **momentumW2;
	float *momentumB;
	float *momentumB2;
	
}GNN;



void initialize(GNN *layer,int numlayers, int Neuron_per_layer[]){
	for(int i = 0;i<numlayers-1;i++){
		layer[i].neuron = Neuron_per_layer[i];
	}
	
	for(int i = 0;i<numlayers-1;i++){
		layer[i].weight = (float**)malloc((layer[i].neuron+1)*sizeof(float*));
		layer[i].momentumW = (float**)malloc((layer[i].neuron+1)*sizeof(float*));
		layer[i].momentumW2 = (float**)malloc((layer[i].neuron+1)*sizeof(float*));
		layer[i].momentumB = (float*)malloc((layer[i].neuron+1)*sizeof(float));
		layer[i].momentumB2 = (float*)malloc((layer[i].neuron+1)*sizeof(float));
		layer[i].delta = (float*)malloc((layer[i].neuron+1)*sizeof(float));
		layer[i].bias = (float*)malloc((layer[i].neuron+1)*sizeof(float));
		for(int j = 0;j< layer[i].neuron; j++){
			layer[i].bias[j] = 0.0;
			layer[i].momentumB[j] = 0.0;
			layer[i].momentumB2[j] = 0.0;
			layer[i].delta[j] = 0.0;
			layer[i].weight[j] = (float*)malloc((layer[i+1].neuron+1)*sizeof(float));
			layer[i].momentumW[j] = (float*)malloc((layer[i+1].neuron+1)*sizeof(float));
			layer[i].momentumW2[j] = (float*)malloc((layer[i+1].neuron+1)*sizeof(float));
			for(int k = 0;k< layer[i+1].neuron ;k++){
				int RANGE = 1e4;	//Xavier Transformation for weights initialization
		        float number = abs(rand() % RANGE);			
				float RANGE = RANGE;
                float p = number / RANGE;
                float y = sqrt(3.0/num_features);
                float x = (p * (-y) + (1.0 - p) * y);
                layer[i].weight[j][k] = x;
				layer[i].momentumW[j][k] = 0.0;
				layer[i].momentumW2[j][k] = 0.0;
			}
		}
	}
}


void forward_prop(Network *node, GNN *layer, int csr[], int dest[]){
	int x = 0, prev = 0;
	for(int l = 0;l<num_layers;l++){
		for(int n = 0;n<num_nodes;n++){
			for(int f = 0;f<layer[l-1].neuron;f++){
				float x = layer[l-1].bias[f];
				for(int i = 0;i<=csr[n];i++){
					if(node[n].labels == node[i].labels){
						x += relu((node[i].features[l-1][f] +node[n].features[l-1][f])*layer[l-1].weight[f][l]);
					}
				}
			}
		}
	}

}

float calc_loss(Network *node, char* loss){
    float loss_val = 0.0;
    for(int j = 0 ; j<num_layers-1;j++){
    	    for(int i=0;i<num_nodes;i++){
		if(strcmp(loss, "mse") == 0){
		    loss_val += (0.5)*(node[i].features[num_layers-1][j] - node[i].labels) * (node[i].features[num_layers-1][j] - node[i].labels);
		}
		else if(strcmp(loss, "ce") == 0){
		    loss_val -= node[i].labels*(log(node[i].features[num_layers-1][j]));
			}
		}
	}
    return loss_val;				 	
}

void backProp(Network *node , GNN * layer, char *loss,char *activation_fun, int itr, char *opt){
	
	for(int i = 0;i<num_nodes;++i){
		for(int j = 0;j<layer[num_layers-1].neuron;++j){		//Error in output layer
			
			if(strcmp(loss, "mse")){
				float grad = sigmoid_d(node[i].features[num_layers-1][j]);
				layer[num_layers-1].delta[j]  = grad*(node[i].features[num_layers-1][j] - node[i].labels);
				}
			else if(strcmp(loss,"ce")){
				layer[num_layers-1].delta[j] = node[i].features[num_layers-1][j] - node[i].labels ;
			}
		}
	}

	
	for(int k = num_layers-2; k>0; k--){ //Backpropagate the error from the last layer to first layer
		for(int n = 0;n< num_nodes; n++){
			        for(int i=0;i<layer[k].neuron;i++){
				    float sum = 0.0;
				    for(int j=0;j<layer[k+1].neuron;j++){
					sum += layer[k].bias[j] * layer[k+1].delta[j];
				    }
				    for(int j=0;j<layer[k+1].neuron;j++){
					sum += layer[k].weight[i][j] * layer[k+1].delta[j];
				    }
				    float grad;
				    if(strcmp(activation_fun, "sigmoid") == 0){
					grad = sigmoid_d(node[n].features[k][i]);
				    }
				    else if(strcmp(activation_fun, "tanh") == 0){
					grad = tanh_d(node[n].features[k][i]);
				    }
				    else if(strcmp(activation_fun, "relu") == 0){
					grad = relu_d(node[n].features[k][i]);
				    }
				    else{
					grad = sigmoid_d(node[n].features[k][i]);
				    }
				    layer[k].delta[i] = grad * sum;
				}
		    }
	}
	
	for(int k=0; k<num_layers-1; k++){	//updating the weights with respect to the optimizer 
		for(int n = 0;n< num_nodes; n++){
			for(int i=0;i<layer[k].neuron;i++){
			    for(int j=0;j<layer[k+1].neuron;j++){

				float dw = layer[k+1].delta[j] * node[i].features[k][i];

				if(strcmp(opt, "sgd") == 0){
				    layer[k].weight[i][j] -= learning_rate * dw;
				}
				else if(strcmp(opt, "momentum") == 0){
				    layer[k].momentumW[i][j] = beta_1 * layer[k].momentumW[i][j] + (1.0-beta_1) * dw * learning_rate;
				    layer[k].weight[i][j] -= layer[k].momentumW[i][j];
				}
				else if(strcmp(opt, "rmsprop") == 0){
				    layer[k].momentumW[i][j] = beta_1 * layer[k].momentumW[i][j] + (1.0-beta_1) * dw * dw;
				    layer[k].weight[i][j] -= (learning_rate * dw)/(sqrt(layer[k].momentumW[i][j]) + 1e-6);
				}
				else if(strcmp(opt, "adam") == 0){
				    layer[k].momentumW[i][j] = beta_1 * layer[k].momentumW[i][j] + (1.0-beta_1) * dw;
				    layer[k].momentumW2[i][j] = beta_2 * layer[k].momentumW2[i][j] + (1.0-beta_2) * dw * dw;
				    float m_cap = (float)layer[k].momentumW[i][j]/(float)(1.0 - pow(beta_1, itr));
				    float v_cap = (float)layer[k].momentumW2[i][j]/(float)(1.0 - pow(beta_2, itr));
				    layer[k].weight[i][j] -= (learning_rate * m_cap)/(sqrt(v_cap) + epsilon);
				}
			    }
			}
		}	
		
		
		for(int j=0;j<layer[k+1].neuron;j++){

		    float db = layer[k+1].delta[j] * 1.0;

		    if(strcmp(opt, "sgd") == 0){
		        layer[k].bias[j] -= learning_rate * db;
		    }
		    else if(strcmp(opt, "momentum") == 0){
		        layer[k].momentumB[j] = beta_1 * layer[k].momentumB[j] + (1.0-beta_1) * db * learning_rate;
		        layer[k].bias[j] -= layer[k].momentumB[j];
		    }
		    else if(strcmp(opt, "rmsprop") == 0){
		        layer[k].momentumB[j] = beta_1 * layer[k].momentumB[j] + (1.0-beta_1) * db * db;
		        layer[k].bias[j] -= (learning_rate * db)/(sqrt(layer[k].momentumB[j]) + 1e-6);
		    }
		    else if(strcmp(opt, "adam") == 0){
		        layer[k].momentumB[j] = beta_1 * layer[k].momentumB[j] + (1.0-beta_1) * db;
		        layer[k].momentumB2[j] = beta_2 * layer[k].momentumB2[j] + (1.0-beta_2) * db * db;
		        float m_cap = (float)layer[k].momentumB[j]/(float)(1.0 - pow(beta_1, itr));
		        float v_cap = (float)layer[k].momentumB2[j]/(float)(1.0 - pow(beta_2, itr));
		        layer[k].bias[j] -= (learning_rate * m_cap)/(sqrt(v_cap) + epsilon);
		    }
		}
	}
}


void train(Network *node , GNN *layer, int csr[], int dest[]){
	float loss_val = 0.0;
	for(int epoch = 0; epoch < num_epochs; epoch++){
		
		forwardProp(node, layer, csr,dest);
		backProp(node ,layer,"ce","tanh",epoch ,"adam");
			loss_val = calc_loss(node, "ce");
			printf("Loss = %f\n",loss_val);
	}
}


int main() {
    Network *nodes = (Network *)malloc(num_nodes * sizeof(Network));
    GNN *layers = (GNN *)malloc(num_nodes * sizeof(GNN));
    initializeGNLayer(layers);
    int dest, csr[num_nodes];
    int i = 0, x = -1;
    int prev = -11111;
    int j = 0;
	int k = 0;
    float destn;
    FILE *feat = fopen("features.txt", "r");
    while (fscanf(feat, "%lf", &destn) == 1) {
        if (j % num_features == 0) {
            j = 0;
			
            nodes[i].features = (double *)malloc(num_features * num_classes * sizeof(double));
            i++;
        }
        nodes[i-1].features[j][k]= destn;
        j++;
		k++;
    }

    FILE *desst = fopen("destination.txt", "r");
    int destination[num_edges];
    i = 0;
    while (fscanf(desst, "%d", &dest) == 1) {
        destination[i] = dest;
        i++;
    }

    int *labels, labl;
    labels = (int *)malloc(num_nodes * sizeof(int));
    FILE *label = fopen("labels.txt", "r");
    i = 0;
    while (fscanf(label, "%d", &labl) == 1) {
        labels[i] = labl;
        i++;
    }

    run(nodes, layers, labels, csr, destination);

    for (int i = 0; i < 500; i++) {
        double prediction = predict(nodes[i].features, layers);
        printf("\nPrediction for node %d: %lf\n", i, prediction);
    }

    return 0;
}
