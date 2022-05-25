#include<iostream>
#include"datamodel.h"
#include<vector>
using namespace std;


vector<Product> allproducts=
{
    Product{1,"Mango",50},
    Product{3,"apple",75},
    Product{7,"WaterMelon",15},
    Product{4,"MuskMelon",20},
    Product{2,"Lichi",100},
    Product{5,"strawberry",150},
    Product{6,"Pineapple",200},
    Product{12,"Orange",30},
    Product{13,"Pomegrante",350},
    Product{9,"Banana",60},
    Product{8,"Guavav",30},
    Product{1,"Grapes",120},
    Product{1,"KachaMango",15},
};

Product* chooseproduct()
{
    //here we are viewing all the products
    string productlist;
    cout<<"Availbale product"<<endl;
    for(auto product:allproducts)
    {
        productlist.append(product.getdisplayname());
    }

    cout<<productlist<<endl;

    cout<<"---------------------------------------"<<endl;
    //here we are choosing a product

    string choice;
    cin>>choice;
    for(int i=0;i<allproducts.size();i++)
    {
        if(allproducts[i].getshortname()==choice)
        {
            return &allproducts[i];
        }
    }

    cout<<"Product not found!!"<<endl;
    return NULL;

}

bool checkout(Cart &cart)
{
    if(cart.isempty())
    {
        return false;
    }
    else
    {
        int total=cart.getTotal();
        cout<<"Pay in cash"<<endl;
        int paid;
        cin>>paid;
        if(paid>=total)
        {
            cout<<"Change "<<paid-total<<endl;
            cout<<"Thank you for shopping with us"<<endl;
            return true;
        }
        else
        {
            cout<<"Not enough cash "<<endl;
            return false;
        }
  }

}

int main()
{
    char action;
    Cart cart;
    while(true)
    {
        cout<<endl;
        cout<<"select an action-(a)dd Item ,(v)iew cart,(c)heckout"<<endl;
        cin>>action;

        if(action=='a')
        {
            //to do:add to cart;
            //view all products+ choose a product+add to cart
            Product * product=chooseproduct();
            if(product!=NULL)
            {
                cout<<"Added to the cart "<<product->getdisplayname()<<endl;
                cart.addproduct(*product);
            }
            
        }
        else
        if(action=='v')
        {
            //view the cart
            cout<<endl;
            cout<<"----------------------------------"<<endl;
            cout<<cart.viewcart()<<endl;
            cout<<"----------------------------------"<<endl;
        }
        else
        {
            //checkout from the cart
            cart.viewcart();
            if(checkout(cart))
            {
                break;
            }

        }
    }

    return 0;
}