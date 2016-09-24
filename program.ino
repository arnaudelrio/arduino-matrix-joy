int reihenPins[8] = {9,3,2,12,15,11,7,6}; 
int spaltenPins[8] = {13,8,17,10,5,16,4,14}; 
const int SW_pin = 0; // digital pin connected to switch output
const int X_pin = 4; // analog pin connected to X output
const int Y_pin = 5; // analog pin connected to Y output
 
int matrix_JOY[8][8]={ 
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
}; 
 
int matrix_1[8][8]={ 
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
}; 
 
int matrix_2[8][8]={ 
{0,0,0,0,0,0,0,0}, 
{0,0,0,0,0,0,0,0},
{0,0,0,1,1,0,0,0},
{0,0,1,0,0,1,0,0},
{0,0,1,0,0,1,0,0},
{0,0,0,1,1,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
};
  
int matrix_3[8][8]={ 
{0,0,0,0,0,0,0,0}, 
{0,0,1,1,1,1,0,0},
{0,1,1,0,0,1,1,0},
{0,1,0,0,0,0,1,0},
{0,1,0,0,0,0,1,0},
{0,1,1,0,0,1,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,0,0,0,0,0},
}; 
 
int matrix_4[8][8]={ 
{0,1,1,1,1,1,1,0}, 
{1,1,0,0,0,0,1,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,1},
{1,1,0,0,0,0,1,1},
{0,1,1,1,1,1,1,0},
};
 
int matrix_5[8][8]={ 
{1,0,0,0,0,0,0,1}, 
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,1},
}; 
 
void setup(){
 
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  //Serial.begin(115200);
 
  for (int i=0; i<8; i++){            
    pinMode(reihenPins[i], OUTPUT);
    pinMode(spaltenPins[i], OUTPUT);
  }
}
 
void loop(){
 
//  Serial.print(":-D");
//  Serial.print("Switch:  ");
//  Serial.print(digitalRead(SW_pin));
//  Serial.print("\n");
//  Serial.print("X-axis: ");
//  Serial.print(analogRead(X_pin));
//  Serial.print("X-convert: ");
//  Serial.print(analogRead(X_pin)/128);
//  Serial.print("\n");
//  Serial.print("Y-axis: ");
//  Serial.println(analogRead(Y_pin));
//  Serial.print("Y-convert: ");
//  Serial.print(analogRead(Y_pin)/128);
//  Serial.print("\n");
 
  if (digitalRead(SW_pin)==0){
    wave();
  }
 
  int yjoy = analogRead(X_pin)/128;
  int xjoy = analogRead(Y_pin)/128;
  matrix_JOY[xjoy][yjoy] = 1;
  printMatrix_JOY();
  // delay (1000);
}
 
void wave(){
 
  clearMatrix_JOY(); //netegem memoria joc
 
  for (int y=0; y<8; y++){                    
    for (int x=0; x<8; x++){           
      if (matrix_1[x][y]==1){                    
        digitalWrite(spaltenPins[x],HIGH);   
      } else {                            
        digitalWrite(spaltenPins[x],LOW);   
      }
    }
    digitalWrite(reihenPins[y],LOW);   
    delayMicroseconds(100);                  
    digitalWrite(reihenPins[y],HIGH);  
  }
  delay (500);
   
  for (int y=0; y<8; y++){              
    for (int x=0; x<8; x++){          
      if (matrix_2[x][y]==1){                   
        digitalWrite(spaltenPins[x],HIGH);    
      } else {                             
        digitalWrite(spaltenPins[x],LOW);     
      }
    }
    digitalWrite(reihenPins[y],LOW);         
    delayMicroseconds(100);            
    digitalWrite(reihenPins[y],HIGH);           
  }
  delay (500);
 
  for (int y=0; y<8; y++){               
    for (int x=0; x<8; x++){          
      if (matrix_3[x][y]==1){                
        digitalWrite(spaltenPins[x],HIGH);    
      } else { 
        digitalWrite(spaltenPins[x],LOW);    
      }
    }
    digitalWrite(reihenPins[y],LOW);         
    delayMicroseconds(100);                 
    digitalWrite(reihenPins[y],HIGH);
  }
  delay (500);
   
  for (int y=0; y<8; y++){                  
    for (int x=0; x<8; x++){                
      if (matrix_4[x][y]==1){                     
        digitalWrite(spaltenPins[x],HIGH);   
      } else {                                 
        digitalWrite(spaltenPins[x],LOW); 
      }
    }
    digitalWrite(reihenPins[y],LOW);      
    delayMicroseconds(100);                   
    digitalWrite(reihenPins[y],HIGH); 
  }
  delay (500);
   
  for (int y=0; y<8; y++){               
    for (int x=0; x<8; x++){          
      if (matrix_5[x][y]==1){            
        digitalWrite(spaltenPins[x],HIGH);   
      } else {                        
        digitalWrite(spaltenPins[x],LOW);     
      }
    }
    digitalWrite(reihenPins[y],LOW);          
    delayMicroseconds(100);                    
    digitalWrite(reihenPins[y],HIGH);         
  }
  delay (500);
   
  delay (1000);
}
 
void printMatrix_JOY(){
 
  for (int y=0; y<8; y++){                  
    for (int x=0; x<8; x++){           
      if (matrix_JOY[x][y]==1){                   
        digitalWrite(spaltenPins[x],HIGH);  
      } else {                               
        digitalWrite(spaltenPins[x],LOW);
      }
    }
    digitalWrite(reihenPins[y],LOW);         
    delayMicroseconds(100);                
    digitalWrite(reihenPins[y],HIGH); 
  }
}
 
void clearMatrix_JOY(){
 
  for (int y=0; y<8; y++){                  
    for (int x=0; x<8; x++){           
        matrix_JOY[x][y]=0;
    }
  }
}
