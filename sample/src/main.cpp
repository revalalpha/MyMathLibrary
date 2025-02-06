#include <iostream>
#include "MyIntrusiveList.h"

class Entity : public mylib::IntrusiveListNode<Entity> {
public:
    int id;

    Entity(int _id) : id(_id) {}

    void print() { std::cout << "Entity ID: " << id << std::endl; }
};

int main() {
    mylib::IntrusiveList<Entity> list;

    Entity e1(1), e2(2), e3(3);

    list.push_back(e1);
    list.push_back(e2);
    list.push_back(e3);

    std::cout << "Liste après ajout :\n";
    for (auto& entity : list)
        entity.print();

    list.remove(e2);

    std::cout << "Liste après suppression de l'entité 2 :\n";
    for (auto& entity : list)
        entity.print();

    return 0;
}
