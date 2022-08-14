#include<iostream>
#include "HUMania.hpp"
#include <vector>
using namespace std;
vector<Unit> pigeons;  // we first define the global vector of type unit for our object pigeons 
vector<Unit> butterfully; // we first define the global vector of type unit for our object butterfully
vector<Unit> bee;// we first define the global vector of type unit for our object bee
int counter=0;  // a counter that will help us in doing the animation synchronously 
void animateObjects(vector<Unit> &duplicate,int location ,int values[4]){ // this helper function will update the values of assessts for srcRect since we have to change the
// srcRect.x srcRect.y srcRect.w srcRect.h values these values were taken from spriteCow website
        duplicate[location].srcRect = {values[0],values[1],values[2],values[3]};  // changing values 
    }  
void animateObjects2(vector<Unit> &duplicate,int location){
    if (duplicate[location].moverRect.x>1000){  // this helper function is made to make the objects appear again from the 
    // other side of the window we first check the size of the window 1000px and then set the condition according to that.
        duplicate[location].moverRect.x = -50; // then we have done -50 because so that it appears that the object is appearing from the other side
    }
    else{

        duplicate[location].moverRect.x += 5; // to move the object in the right direction
    }
}
void pigeonObject(SDL_Renderer* gRenderer, SDL_Texture* assets){
    for (int i = 0;i<pigeons.size();i++){   // helper function created for object pigeon that will help in animation
    if (counter%3==0){   // used the logic mod counter%3==0 so first image of pigeon should appear 
        int values[4]={7,88,155,103};  // sprite cow values 
        animateObjects(pigeons,i,values);   // calling helper function to update the srcRect 
        counter=0; // setting the counter equal to 0 so that counter don't updated indefinitely 
     } 
    else if (counter%3==1){
        int values[4]={0,237,153,84};    // second image of the pigeon so that it appears as if it is flying 
        animateObjects(pigeons,i,values);  // updating values 
    }
    else if (counter%3==2){
        int values[4]={2,361,159,124};   // third image of the pigeon
       animateObjects(pigeons,i,values);   // updating values 
    }
    animateObjects2(pigeons,i);     // checking the condition that if pigeon greater than 1000 so set moverRect.x =0 or update to +5
    SDL_RenderCopy(gRenderer, assets, &pigeons[i].srcRect, &pigeons[i].moverRect); // to dispaly the graphics on the window with the updated animation
    }
}
void butterflyObject(SDL_Renderer* gRenderer, SDL_Texture* assets){
    for (int i = 0;i<butterfully.size();i++){ // helper function created for object butterfly that will help in animation
    if (counter%3==0){        // used the logic mod counter%3==0 so first image of butterfly should appear 
    int values[4]={257,24,173,134}; // sprite cow values 
    animateObjects(butterfully,i,values); // calling helper function to update the srcRect 
    // counter=0;
    } 
    else if (counter%3==1){             // second image of the butterfly so that it appears as if it is flying 
    int values[4]={257,182,192,214}; // updating values 
    animateObjects(butterfully,i,values);
    }
    else if (counter%3==2){   // third image of the butterfly
    int values[4]={248,432,248,179};  // updating values 
    animateObjects(butterfully,i,values);
    }
    animateObjects2(butterfully,i);      // checking the condition that if butterfly greater than 1000 so set moverRect.x =0 or update to +5
    SDL_RenderCopy(gRenderer, assets, &butterfully[i].srcRect, &butterfully[i].moverRect);
    }  
}
void beeObject(SDL_Renderer* gRenderer, SDL_Texture* assets){
    for (int i = 0;i<bee.size();i++){   // helper function created for object bee that will help in animation
    if (counter%3==0){       // used the logic mod counter%3==0 so first image of bee should appear
    int values[4]={527,138,194,116};   // sprite cow values 
    animateObjects(bee,i,values);      // calling helper function to update the srcRect 
    // counter=0;
    }
    else if (counter%3==1){   // second image of the bee so that it appears as if it is flying 
    int values[4]={527,254,194,116};   // updating values 
    animateObjects(bee,i,values);
    }
    else if (counter%3==2){   // third image of the bee
    int values[4]={540,370,193,115};  // updating values 
    animateObjects(bee,i,values);
    }
    animateObjects2(bee,i);   // checking the condition that if bee greater than 1000 so set moverRect.x =0 or update to +5
    SDL_RenderCopy(gRenderer, assets, &bee[i].srcRect, &bee[i].moverRect);  // to dispaly the graphics on the window with the updated animation
    }
}
void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){  //main function in which we will call all other helper fucntions 
    SDL_Delay(10);    // adding the delay for the animation
    pigeonObject(gRenderer,assets); // calling function for pigeion
    //-------------------------------------------------------------------------------------//
    butterflyObject(gRenderer,assets);  // calling function for butterfly
    //---------------------------------------- -----------------------------------------------//
    beeObject(gRenderer,assets);   // calling function for bee
    counter++;
}
  // SDL_RenderPresent is already called in game.cpp file, you don't need to call here
void createObject(int x, int y){   
    // create an object randomly, and push it into corresponding vector
    std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
    int random = 1 + (rand()%3); // creating random values from 1 till 3 
    if (random==1){              // if the value generated by random is 1 create a pigeon object and push it to the vector pigeon 
        Unit pigeon1 = {{7,88,155,103}, {x, y,40, 40}}; // 
        pigeons.push_back(pigeon1);}
    else if (random==2){  // if the value generated by random is 2 create a butterfly object and push it to the vector butterfly
        Unit butterfly1 = {{257,24,173,134},{x,y,40,40}};
        butterfully.push_back(butterfly1);
    }
    else if (random==3){ // if the value generated by random is 3 create a bee object and push it to the vector bee
        Unit bee1 = {{527,138,116},{x,y,40,40}};
        bee.push_back(bee1);
    }
}

