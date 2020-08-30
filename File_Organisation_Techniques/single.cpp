/* System Software Lab - Single Level Directory Structure
S Sandeep Pillai
59
CS4A

<Licence> 
 This Code belongs to S Sandeep Pillai. Feel free to copy and submit the assignment for free marks. 
 For commercial use, please gpay me 10% of all profits. K thanks.
</Licence>


*/

#include <iostream>
#include <vector>
 

using namespace std;

struct file{
    string name;
    int id;
    float size;
    bool read_only;
    bool hidden;

};

class directory{
    private:
        string name;
        int file_count;
        std::vector<file> directory_files; 

    public:

        directory(string name1){
                name = name1;
                file_count = 0;
        }

        void create_file();
        void erase_file();
        void display_files();
        
        

};

void directory::create_file(){
    file new_file;
    cout<<endl<<endl<<"Enter file name: ";
    cin>> new_file.name;
    cout<<"Enter file size(Kb): ";
    cin>> new_file.size;           
    ++file_count;
    new_file.id = file_count;
    new_file.read_only = false;
    new_file.hidden = false;
    bool already_exists = false;

    for(int i=0; i<directory_files.size(); i++){
            if(directory_files[i].name == new_file.name){
                cout<<"\nThis file already exists in this directory! Pick Another Name! \n";
                already_exists = true;
            }
        
        }

    if(!already_exists){
        directory_files.push_back(new_file);
    }
}

void directory::erase_file(){
    if(file_count <=0){
        cout<<"The directory is already empty!" ;
    }
    else{
        string buffer;
        cout<<"\nEnter the file to delete: ";
        cin>> buffer; 
        bool found = false;


        for(int i=0; i<directory_files.size(); i++){
            if(directory_files[i].name == buffer){
                directory_files.erase(directory_files.begin() +i);
                found=true;
                --file_count;
            }
        
        }

        
        if(!found){
            cout<<"\nFile not found!" ;
        }

    }
    cout<<endl<<endl;

    
}

void directory::display_files(){
    

    file temp;
    cout<<endl<<endl<<"Total Number of files: "<< file_count << endl;
    cout<<"\n~Root:";
    for(int i=0; i<directory_files.size(); i++){
        cout<<"| "<< directory_files[i].name;
        cout<<"("<<directory_files[i].size<<" Kb)\n      ";

    }
    cout<<endl<<endl;

}

void Menu(){

    char choice='A';
    directory root("~root");
    cout<<"Welcome! This program will help visualise a single directory file system";
    cout<<endl<<endl<<"Please select an option to proceed:"<<endl;
    cout<<"[C] Create File\n";
    cout<<"[E] Erase File\n";
    cout<<"[D] Display Files\n";
    cout<<"[Q] Exit Program\n";
    while(choice!='Q'){
    cout<<"\n<***********************************************>";
    cout<<"\n([H] for help)\n-> " ;
    cin>>choice;
    choice = toupper(choice);
        switch(choice) {
            case 'C':
                root.create_file();
                break;
            case 'D':
                root.display_files();
                break;
            case 'E': 
                root.erase_file();
                break;
            case 'Q':
                cout<<"\nGoodbye!\n";
                break;
            case 'H':
                cout<<"\n(Input Case does not matter)";
                cout<<"\n[C] Create File\n";
                cout<<"[E] Erase File\n";
                cout<<"[D] Delete File\n";
                cout<<"[Q] Exit Program\n";
                break;
            default:
                cout<<"\nIncorrect option, try again!\n";
        }
    }
}


int main(){

    directory root("root"); 
    Menu();

}