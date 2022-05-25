//we will make three classes product ,item,cart
#include<string.h>
#include<unordered_map>
using namespace std;

class Item;
class Cart;

class Product
{
    int id;
    string name;
    int price;
    public:

    Product()
    {
        //this is default constructor it would be automatically deleted after the scope is over
    }

    Product(int u_id,string name,int price)
    {
        id=u_id;
        this->name=name;
        this->price=price;
    }

    string getdisplayname()
    {
        return name + " : Rs " + to_string(price) + "\n";
    }

    string getshortname()
    {
        return name.substr(0,1);
    }

    friend class Item; 
    friend class Cart;                    // making item class friend to Product

};

class Item
{
    Product product;
    int qty;
    public:
    Item(){}

    Item(Product p,int q):product(p), qty(q)
    {
        
    }

    int getitemprice()
    {
        return qty*product.price;           //this price is private member to product class 
    }

    string getiteminfo()
    {
        return to_string(qty) + " * " + product.name + " Rs. " + to_string(qty*product.price)+'\n';
    }

    friend class Cart;
};

// in cart we will use hash map 
class Cart
{
    unordered_map<int,Item> items;
    public:

    //this is the method by which we can add items to the cart

    void addproduct(Product product)
    {
        if(items.count(product.id)==0)             //if that item is new in tha map
        {
            Item newitem(product,1);
            items[product.id]=newitem;
        }
        else
        {
            items[product.id].qty+=1;               // if that item is already present

        }
    }

    int getTotal()
    {
        //todo
        int total=0;
        for(auto itempair:items)
        {
            auto item=itempair.second;
            total+=item.getitemprice();
        }

        return total;

    }

    //method to view the cart

    string viewcart()
    {
        if(items.empty())
        {
            return "cart is empty";
        }
        else
        {
            string itemlist;
            int cart_total=getTotal();

            for(auto itempair:items)
            {
                auto item=itempair.second;
                itemlist.append(item.getiteminfo());
            }

            return itemlist + "\n Total price : Rs. " + to_string(cart_total) + '\n';

        }
    }

    bool isempty()
    {
        return items.empty();
    }


};