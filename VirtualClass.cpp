#include<iostream>

//[file=virtualclass.html title=""]
class MyInterface{
    public:
        int id;
    public:
    virtual void play() = 0;
    virtual void getID() = 0;
};

class MusicPlay : public MyInterface{
    public:
        MusicPlay(){
            id = arc4random_uniform(100);
        }
    public:
    virtual void play(){
        printf("MusicPlay play()\n"); 
    }
    virtual void getID(){
        printf("id=[%d]\n", id); 
    }
};

class VideoPlay : public MyInterface{
    public:
        VideoPlay(){
            id = arc4random_uniform(100);
        }
    public:
    virtual void play(){
        printf("VideoPlay play()\n"); 
    }
    virtual void getID(){
        printf("id=[%d]\n", id); 
    }
};


class TopClass{
    public:
        TopClass(){}
    public:
        void draw(){
            printf("TopClass draw()\n"); 
        }
};

class TopSubClass : public TopClass{
    public:
        TopSubClass(){
        }
        void draw(){
            printf("TopSubClass draw()\n"); 
        }
        
};

class MainClass{
    public:
        MainClass(){
        }
    public:
        virtual void draw(){
            printf("MainClass draw()\n"); 
        }
        virtual void fun1() = 0;

        virtual void overrideFun(){
            printf("MainClass overrideFun\n"); 
        }

};

class SubMainClass: public MainClass{
    public:
       SubMainClass(){} 

    public:
        virtual void draw(){
            printf("SubMainClass draw()\n"); 
        }

        void overrideFun(){
            printf("SubMainClass overrideFun\n"); 
        }

        virtual void fun1(){
            printf("SubMainClass fun1\n"); 
        }
};
//]

void test0(){
    printf("test0()--------------------------\n");
    MyInterface* f = new MusicPlay();
    f->play();
    f->getID();
    f = new VideoPlay();
    f->play();
    f->getID();
    printf("---------------------------------\n");
}
int main()
{
    MainClass* topClass;
    SubMainClass subClass;

    topClass = &subClass;
    topClass->fun1();
    topClass->overrideFun();
    SubMainClass* sub = new SubMainClass();
    sub->overrideFun();
    topClass = sub;
    topClass->overrideFun();

    TopClass* nc = new TopClass();
    nc->draw();
    nc = new TopSubClass();
    nc->draw();

    TopSubClass* in = new TopSubClass();
    in->draw();
    test0();
}

