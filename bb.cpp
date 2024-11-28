#include <iostream>
using namespace std;
class Shop{
    int Price[100];
    int itemNo[100];
    int counter=0;
    public:
    void initCounter(){
        counter=0;
    }
    void setPrice();
    void displayPrice();
};
void Shop::setPrice(){
    cout<<"Enter id of your item no "<<counter+1<<endl;
    cin>>itemNo[counter];
    cout<<"Enter price of your item "<<endl;
    cin>>Price[counter];
    counter++;
}
void Shop::displayPrice(){
    for(int i=0;i<counter;i++){
        cout<<"The price of item no "<<itemNo[i]<<" is "<<Price[i]<<endl;
    }
}
int main (){
    Shop dukan;
    dukan.setPrice();
    dukan.setPrice();
    dukan.setPrice();
    dukan.displayPrice();
    return 0;
}