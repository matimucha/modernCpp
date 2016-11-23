#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<Shape*> ;

bool sortByArea(Shape* first, Shape* second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(Shape* s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(Shape* s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(const auto& element : collection)
    {
        if(element)
        {
            element->print();
        }
    }
}

void printArea(std::string name, double area)
{
    std::cout << "thread_id: " << std::this_thread::get_id() << " - " << name << ": " << area << std::endl;
}

void printAreas(const Collection& collection)
{
    std::vector<std::thread> threads;
    for(const auto& element : collection)
    {
        if(element)
        {
            std::thread th(printArea, element->getName(), element->getArea());
            threads.push_back(std::move(th));
        }
    }
    for(auto& thread : threads)
    {
        thread.join();
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << std::endl << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << std::endl << "There is no shape matching predicate " << info << endl;
    }
}


class BlockingQueue
{
public:
    void push(Shape* shape)
    {
        // TODO
    }

    Shape* pop()
    {
        // TODO
        return nullptr;
    }
};

BlockingQueue g_queue;

void runQueue()
{
    constexpr auto running = true;
    while(running)
    {
        Shape * shape = g_queue.pop();
        if(shape == nullptr)
        {
            std::cout << "Queue received nullptr, finishing loop" << std::endl;
            break;
        }
        else
        {
            std::cout << "Shape on queue: " << shape->getName() << std::endl;
        }
    }
}

void pushShapesToQueue(Collection const& shapes)
{
    for(auto shape : shapes)
    {
        g_queue.push(shape);
    }
}

void printColors(Collection const& shapes)
{
    for(auto& shape : shapes)
    {
        if(shape)
            std::cout<<"Shape: "<< shape->getName() << " Color is: " << shape->getColor() <<std::endl;
        else std::cout<<"Undefined shape or shape color missing"<<std::endl;
    }
}

int main()
{
    Collection shapes;
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Circle(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(new Circle(4.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Circle(4.0));

    printCollectionElements(shapes);

    cout << std::endl << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << std::endl << "Areas after sort: " << std::endl;
    printAreas(shapes);

    std::cout<<"Shapes colors are: "<<std::endl;
    printColors(shapes);

    auto square = new Square(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    std::thread queueThread(runQueue);
    pushShapesToQueue(shapes);

    queueThread.join();

    return 0;
}
