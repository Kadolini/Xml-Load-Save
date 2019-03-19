/**
Utilisation de TinyXML :
Pour parser un fichier XML aura besoin d'utiliser une methode :
soit SAX ou DOM.
Avantages SAX:
  - Low memory consumption
  - Low memory fragmentation
  - High execution speed
Avantages DOM:
  - Easier to understand
  - Slightly easier to implement
  - Sequence of data in XML file is irrelevant



Un fichier XML de SAVE contient :
Les différents niveaux. //vector<string> avalaible_levels
Les differentes informations sur chaque niveau :
  - Le niveau courant // Game Level *current_level
  - Niveau réussi ou non // bool info_niveau
  - Les différents essai tapé par le joueur. // std::vector<vector<string>> essai;
  - Moyenne pour memoriser les differents essai std::vector<float> out;
  -
save_in_file va sauver dans un fichier XML les données.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

void save_in_file(){

}

void saveData(){
  //unsigned int pos = 0, start;
  string found, line;
  //vector<bool> succeeded_levels;
  ofstream myfile ("jeu.xml");
  if (myfile.is_open()) // file opened
  {
  //  if(info_niveau){ // je sais plus
  	line=File.get();
    found = "<level>"

  	while(!File.eof()){ // Not at the end of the file
  		if(found.compare(line)==0){// compare found with the line to get the exact position.
        myfile << " <lvl> \n";
        myfile << "  <current_level>save</current_level> \n";
      //  myfile << "  <congrats>"+ succeeded_levels +"</congrats>\n";
      //  myfile << "  <trial>\n";
      //  myfile << "    <try></try>\n";
      //  myfile << "  </trial>\n";
      //  myfile << "  <average></average>\n";
        myfile << " </lvl>\n";
      }
  	}
    std::cout << "Progression Saved . . ." << '\n';
    myfile.close();
  //}
  else cout << "Unable to open file";
  }
}

void succeededLevel(){
  string found, line;
  //vector<bool> succeeded_levels;
  ofstream myfile ("jeu.xml");
  if (myfile.is_open()) // file opened
  {
    if(succeeded_levels){
    line=File.get();
    found = "</current_level>"

    while(!File.eof()){ // Not at the end of the file
      if(found.compare(line)==0){// compare found with the line to get the exact position.
        myfile << "\n" // retour a la ligne car on found </current_level>
        myfile << "  <congrats>"+ succeeded_levels +"</congrats>\n";
      }
    }
    myfile.close();
  }
  else cout << "Unable to open file";
  }
}

void addTry(){ // Add all of the tests the player send

  string found;
  // En commentaire car la variable se trouve déjà dans GameSequence.h
  // vector<vector<string>> attempts;

  ofstream myfile ("jeu.xml");
  if (myfile.is_open()) // file opened
  // if()
  {
    if(current_level){
      line=File.get();
      found = "<trial>"

      while(!File.eof()){ // Not at the end of the file
        if(found.compare(line)==0){// compare found with the line to get the exact position.
          //myfile << "  <trial>\n";
          myfile << "    <try>\n";
          myfile << "     " + attempts;
          myfile << "    </try>\n";
        }
      }
      myfile.close();
  }
  else cout << "Unable to open file";
  }
}

void addAverage(){ // Add all of the tests the player send

  string found; // Word to find
  // En commentaire car la variable se trouve déjà dans GameSequence.h
  // vector<bool> attempted; // Boolean if there is attempts
  // vector<vector<float>> average_speed;
  // vector<vector<float>> average_memory_use;

  ofstream myfile ("jeu.xml"); //Path of the XML file
  if (myfile.is_open()) // file opened
  {
    if(attempted){ // if the level is solved. It is attempted not attempts
      line=File.get();
      found = "<average>"

      while(!File.eof()){ // Not at the end of the file
        if(found.compare(line)==0){// compare found with the line to get the exact position.
          //myfile << " <lvl> \n";
          myfile << " <avg>\n";
          myfile << "   " + average_speed; // variable who insert the average.
          myfile << "   " + average_memory_use; // variable who insert the average.
          myfile << " </avg>\n";
          //myfile << " </lvl>\n";
        }
      }
      myfile.close();
  }
  else cout << "Unable to open file";
  }
}
