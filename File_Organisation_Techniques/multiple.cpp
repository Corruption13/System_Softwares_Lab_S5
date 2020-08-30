/* System Software Lab - Two Level Directory Structure
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


////////////////////////////////////////////////////////////////////////////////////////////////////

//   Global Variables/Structures below 

///////////////////////////////////////////////////////////////////////////////////////////////////

int USERCOUNT = 0;

struct file{
    string name;
    int id;
    float size;
    bool read_only;
    bool hidden;

};

void cls(){
    for(int i = 0; i < 100; i++)
        cout<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

//   Directory CLASS below

///////////////////////////////////////////////////////////////////////////////////////////////////

class directory{
    private:
        string name;
        int file_count;
        string user;
        std::vector<file> directory_files; 

    public:

        directory(string name1="root", string user = "root"){
                name = name1;
                file_count = 0;
                user = user;

        }

        void create_file();
        void erase_file();
        void display_files();

        
        

};

void directory::create_file(){
    file new_file;

    cout<<endl<<"Enter file name: ";
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
    cout<<endl<<endl<<"     ";
    cout<<name<<" (" << file_count << "):\n         ";
    for(int i=0; i<directory_files.size(); i++){
        cout<<"| "<< directory_files[i].name;
        cout<<"("<<directory_files[i].size<<" Kb)\n         ";

    }
    cout<<endl;


}

////////////////////////////////////////////////////////////////////////////////////////////////////

//   USER CLASS below

///////////////////////////////////////////////////////////////////////////////////////////////////

class user_partition{
    private:
        string u_name;
        int id;
        string password;
        
    public:
        directory home_folder;
        user_partition(string u_name1, int id1, string password1){

                u_name = u_name1;
                id = id1;
                password = password1; 
                directory temp(u_name, u_name);
                home_folder = temp;
        }
        string get_name(){
            return u_name;
        }

};

void create_user(std::vector<user_partition> &users){
    string name;
    string password;
    
    cout<<"Enter user name: " ;
    cin>>name;
    cout<<"Enter user password: ";
    cin>>password ; 
    USERCOUNT++;
    user_partition new_user(name, USERCOUNT, password);
    users.push_back(new_user);

    

}

void delete_user(std::vector<user_partition> &users){
    string name;
    bool found = false;
    
    cout<<"Enter user name: " ;
    cin>>name;

    for(int i = 0; i < users.size(); i++){
        if(users[i].get_name() == name){
            found = true;
            users.erase(users.begin() + i);
            USERCOUNT--;
        }
    }

    

}

void user_list_view(std::vector<user_partition> &users){
    if (users.size() == 0){
        cout<<"\nNo users! Input [U] to create one! \n" ;
    }
    else{
        cout<<"\nUser List View: \n";
    }
    for(int i = 0; i < users.size(); i++){
       cout<<endl<<i+1<<") "<< users[i].get_name();
    }
    cout<<endl;
}

void two_level_view(std::vector<user_partition> &users){
    if (users.size() == 0){
        cout<<"\n Please create a user first.\n" ;
    }
    else{
        cout<<"\nFile Directory View: \n";
    }
    for(int i = 0; i < users.size(); i++){
       users[i].home_folder.display_files();
    }
}


void new_file_wrapper(std::vector<user_partition> &users){

    if (users.size() == 0){
        cout<<"\n Please create a user first.\n" ;
    }


    string user_name;
    bool found = false;
    cout<<"\nEnter Username: ";
    cin>> user_name ;

    for(int i = 0; i < users.size(); i++){
        if(users[i].get_name() == user_name){
            found = true;
            users[i].home_folder.create_file();
            USERCOUNT--;
        }
    }
    if(found == false){
        cout<<"\nUser not found!\n";
    }
}

void erase_file_wrapper(std::vector<user_partition> &users){\

    if (users.size() == 0){
        cout<<"\n Please create a user first.\n" ;
    }

    string user_name;
    bool found = false;
    cout<<"\nEnter Username: ";
    cin>> user_name ;

    for(int i = 0; i < users.size(); i++){
        if(users[i].get_name() == user_name){
            found = true;
            users[i].home_folder.erase_file();
            USERCOUNT--;
        }
    }
    if(found = false){
        cout<<"\nUser not found!\n";
    }

}


////////////////////////////////////////////////////////////////////////////////////////////////////

//   Driver Functions below 

///////////////////////////////////////////////////////////////////////////////////////////////////

void Menu(){

    char choice='A';
    directory root("~root");
    std::vector<user_partition> users; 


    cout<<"Welcome! This program will help visualise a single directory file system";
    cout<<endl<<endl<<"Please select an option to proceed:"<<endl;
    cout<<"[U] Create new User\n";
    cout<<"[L] Delete a User\n"; 
    cout<<"[V] View Users Table\n";
    cout<<"[C] Create File\n";
    cout<<"[E] Erase File\n";
    cout<<"[D] Display Files\n";
    cout<<"[Q] Exit Program\n";
    while(choice!='Q'){
    cout<<"\n!***********************************************!";
    cout<<"\n([H] for help)\n-> " ;
    cin>>choice;
    cls();
    choice = toupper(choice);
        switch(choice) {
            case 'U':
                create_user(users);
                break;
            case 'I':
                delete_user(users);
                break;
            case 'V':
                user_list_view(users);
                break;
            case 'C':
                new_file_wrapper(users);
                break;
                
            case 'D':
                two_level_view(users);
                break;
            case 'E': 
                erase_file_wrapper(users);
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
