#include<list>
#include<string>
#include<iostream>
#include<algorithm>
#include <stdlib.h> 
using namespace std;
 
class TrieNode{//Represents Trie elements in which we gonna push letter and translation for the words if there are any 
public:
    char key;
    string meaning;
    list<TrieNode *> children; 
    TrieNode(char k,string translation=string("")){//we set default value of our translation
        key=k;
        if(translation.empty()){//This is called taftology :)
            translation.clear();//Just in case
        }else{
            meaning=translation;
        }
    }
};

class Trie{//This class represents our Trie dictionary. Here we add words and make translations
private:
     TrieNode* root;
     
public:
    Trie(){
        root=new TrieNode('!',"");
    }
    TrieNode* getRoot(){//here we get the root element of our Trie
        return root;
    }
    void print(TrieNode* root){//for debuging purposes
        if(root==NULL){
            return;
        }
        cout<<root->key<<endl;
        for(list<TrieNode*>::iterator it=root->children.begin();it!=root->children.end();it++){
            print(*it);
        }
    }
    
    TrieNode* addLetter(TrieNode* root, char letter, string meaning=""){//here we add specific letter in its specific place
        root->children.push_front(new TrieNode(letter,meaning));    
        list<TrieNode*>::iterator it=root->children.begin();
        return (*it);//we return the reference to the pointer of our new letter
    }
    
    void addTranslation(TrieNode* root, string meaning){//adding translation to the last letter of our word
        root->meaning=meaning;
    }
    
    bool seachNode(TrieNode* root,char letter,TrieNode*& returnRoot){//seeking for specific letter in our Trie
        for(list<TrieNode*>::iterator it=root->children.begin();it!=root->children.end();it++){//return true if we find it
            if((*it)->key==letter){
                returnRoot=(*it);
                return true;
            }         
        }
    return false;
    }
    
    bool getTranslation(TrieNode* root, string& translation){//here we get the translation of the root level
        if(!root->meaning.empty()){//if we don't have one, we return empty string
            translation=root->meaning;
            return true;
        }
        return false;
    }

    string nextWord(string& word){//helper method which returns our text the next 'word' in the front
        if(word.empty()){
            return "";
        }
        
        int place=0;
        string saveResult;
        for(string::iterator it=word.begin();it!=word.end()&&(*it)!=' ';it++){
            place++;
            saveResult+=(*it);
        }
        string test="";
        if(place==0){
            return "";
        }else{
            string test(word.begin()+place,word.end());
            if(*test.begin()==' '){
                place=0;
                for(string::iterator it=test.begin();it!=test.end()&&(*it)==' ';it++){
                    place++;          
                }
                string s(test.begin()+place,test.end());
                test=s;
            }
            word=saveResult;
            return test;        
        }
        
    }
    
    string translateText(string& text){
        std::transform(text.begin(),text.end(),text.begin(),::tolower);//transforming my string to lower case
        int count=0;
        int index=0;
        string result;
        string workingText=text;
        string translation;
        string::iterator string_iterator=text.begin();
        try{
            while(workingText!=""||string_iterator==text.end()){//iterating over the variations of words
                string temp=translateWord(root, workingText, string_iterator);
                if(temp==""){//if you don't have translation we get to the next word if we can
                    string saveResult=workingText;
                    workingText=nextWord(saveResult);
                    result.append(saveResult);
                    result.append(" ");
                }else{//otherwise we filter the true content of the word if we have one
                result.append(temp);
                result.append(" ");
                string temporary;
                string::iterator helper_iterator=string_iterator;
                while(*helper_iterator!=0){//copy to helper variable
                    temporary+=*(helper_iterator++);   
                }
                int place=0;
                string::iterator iter=temporary.begin();
                while(iter!=temporary.end()&&(*iter)!=' '){//we don't want additional letters to our word
                        place++;      
                        iter++;
                }
                string kiro1(iter,temporary.end());
                place=0;
                for(string::iterator it=kiro1.begin();it!=kiro1.end()&&(*it)==' ';it++){//we ignore whitespaces
                        place++;   
                    }
                string kiro(kiro1.begin()+place,kiro1.end());
                workingText=kiro;
                }
            }
            
        }
        catch(const char* str){
            cout<<str;
        }
         catch(...){
           cout<<"exception";
        }
        return result;
        
    }
    
    string translateWord(TrieNode* root,string& word,string::iterator& current){//method for translation of specific text that
        TrieNode* helper;//is saved in our trie dictionary
        string temporaryResult,result;
        if(word.empty()){
            return "";
        }
        string::iterator it=word.begin();
        while(it!=word.end()){
            char key=static_cast<char>(*it);
            if(seachNode(root,key,helper)){
                root=helper;
                getTranslation(root,result);
                result.append(temporaryResult);
                it++;
                current=it;
            }else
                break;
        }
      
        return result;
    }
    
    void addWord(TrieNode* root , string& word, const string& translation){//Method for adding a word into our TrieDictionary
                TrieNode* helper=new TrieNode(' ',"");//this variable help us to set root element to our searchings
                for(string::iterator it=word.begin();it!=word.end();it++){//true
                    char key=static_cast<char>(*it);
                    if(seachNode(root,key,helper)){
                  //      cout<<(*it);
                        root=helper;//Very important thing! Here we took the address of our helper variable
                    }               //to use like root element of our new operations(search) or adding translation
                    else{
                        helper=addLetter(root,key,"");//Here we took the reference to the new letter
                        root=helper;                            //with helper variable and then use it like a root
                    }
                }
                addTranslation(root,translation);//here we add translation to our word
              //  cout<<root->meaning<<endl;
    }
    
};

void init(Trie& k){
    string a("ass");
    string b("zadnik");
    string c("asset");
    string d("proverka");
    string e("raining cats and dogs");
    string f("vali kato iz vedro");
    string x("hello");
    string z("zdravei");
    string x1("you");
    string z1("ti");
    string x2("are");
    string z2("si");
    k.addWord(k.getRoot(),a,b);
    k.addWord(k.getRoot(),c,d);
    k.addWord(k.getRoot(),e,f);
    k.addWord(k.getRoot(),x,z);
    k.addWord(k.getRoot(),x1,z1);
    k.addWord(k.getRoot(),x2,z2);


}

int main() {
   // TrieNode* q=new TrieNode('!',"");
    Trie k;
    string word;
    string translation;                                 
    
 //   k.print(k.getRoot());//hmmmmmmm
    while(true){
        cout<<"Please make your choice: "<<endl;
        cout<<"1. Initialize the Trie dictionary"<<endl;
        cout<<"2. Add word(expresion) and translation"<<endl;
        cout<<"3. Translate text"<<endl;
        cout<<"4. Exit"<<endl;
        char a[1024];
        cin.getline(a,1024);
        if(a[0]=='1'){
            init(k);
            cout<<"Trie Dictionary inizialized"<<endl;
        }else if(a[0]=='2'){
            cout<<"Please enter your word(expresion)"<<endl;
            char word[1024];
            cin.getline(word, 1024);
            cout<<"Please enter your translation"<<endl;
            char translation[1024];
            
            cin.getline(translation,1024);
            string w(word),t(translation);
            k.addWord(k.getRoot(),w,t);
        }else if(a[0]=='3'){
            cout<<"Please enter your text to translate"<<endl;
            char temp[1024];
            cin.getline(temp,1024);
            string cc(temp);
            string tr;
            tr=k.translateText(cc);
            cout<<endl<<"Translation is:"<<endl;
            cout<<tr<<endl<<endl;
        }else if(a[0]=='4'){
            cout<<"Bye"<<endl;
            return 0;
        }else{
            cout<<endl<<"Incorect input. Try again (1-4)"<<endl<<endl;
        }
    }
    
}

