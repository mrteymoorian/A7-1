#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Film.h"
#include "Exception.h"

class Film;

class Notification{
public:
    Notification(std::string _content){ content = _content;}
    std::string get_content(){ return content;}
    bool has_been_read(){ return read;}
    void the_person_read(){ read = true;}
private:
    std::string content;
    bool read = false;

};



class Person{
public:
    Person(std::string user, std::string pass , std::string _email, int _age , int _id){
        username = user;
        password = pass;
        email = _email;
        age = _age;
        id = _id;
        
    }
    
    std::string get_username(){ return username;}
    std::string get_password(){ return password;}
    std::string get_email(){ return email;}
    int get_id(){ return id;}
    virtual std::string get_type () = 0;
    virtual void add_film(Film* NewFilm){}
    virtual void delete_film(int film_id){}
    virtual void show_followers(){}
    virtual void show_published_films(std::vector <std::string> word){}
    virtual void reply_comment(int film_id ,int comment_id,std::string content){}
    virtual bool follow(Person* p){}

    void show_purchased_films(std::vector <std::string> word);
    void give_notification(std::string content);
    void inc_money(float amount){ money += amount;}
    bool buy_film(Film* newfilm ,int price);
    void rate_film(Film* newfilm , int score);
    bool has_rated_this_film(int film_id);
    int get_score_of_this_film(Film* this_film){ return rated_film_with_score[this_film];}
    void comment_on_this_film(int film_id, std::string content);
    bool have_bought_this_film(int film_id);
    void show_unread_notifications();
    void show_read_notifications(int limit);

protected:
    std::string username;
    std::string password;
    std::string email;
    int age;
    int id;
    float money = 0;
    std::vector <Notification> notification;
    std::vector <Film*> bought_film;
    std::map <Film* , int> rated_film_with_score;
    std::vector <Film*> rated_film;
    

};










#endif