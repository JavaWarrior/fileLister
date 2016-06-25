#include <iostream>
#include <vector>
#include <dirent.h>

using namespace std;


bool exitFlag=  false;
vector<string> files;
char * fileName ="dumpy";
bool eflag = false;
void selectDirec(){
    files.clear();
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (".")) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        if(opendir(ent->d_name) == NULL){
            files.push_back(ent->d_name);
        }
      }
      closedir (dir);
    } else {
    eflag = true;
      cout<<"directory error"<<endl;
    }
    files.push_back("exit");
}
void selectFile(){
    selectDirec();
    cout<<"choose file"<<endl;
    for(int i = 0 ; i < files.size() ; i++){
        cout<<i+1<<" : "<<files[i]<<endl;
    }
    int choice = 0;
    cout<<"enter file number"<<endl;
    cin>>choice;
    if(choice == files.size()){
        exitFlag = true;
        return;
    }
    choice--;
    fileName = const_cast<char*>(files[choice].c_str());

}

int main(void){
	selectFile();
	cout<<"your file name is: "<<fileName<<endl;
	return 0;
}