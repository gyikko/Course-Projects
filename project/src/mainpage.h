/**
 * @file mainpage.h
 *
 * @copyright 2020 Jingyi Jin, All rights reserved.
 */
/*! \mainpage Transit Simulator and Visualization Project 
 *
 * \section intro_sec Introduction
 * The transit simulator and visualization project simulates buses' information, stops' locations, the amount
 * of loaded passengers, and the number of unloaded passengers, when they are running on provided routes, and
 * visualized the information by using red dots to present buses, and showing the movement on a real map.
 * 
 * \subsection obtain_sec How to obtain?
 * To obtain the code, simpily download the project from github. Or, you can choose to use git clone command
 * to copy the project in your local devices.
 * 
 * \subsection config_sec How to configure?
 * To run the program, first you need to make sure you're running the code in Unix environment. Meanwhile,
 * another tool you need for running the code is a browser.
 * 
 * \subsection compile_sec How to compile?
 * After downloading the code, use `cd` command to change the current location to src file under project
 * directory. Then, use `make` command to compile the code, all the files will be compiled directly.
 * You can also use `make clean` command to clean all the built objects.
 * 
 * \subsection execute_sec How to execute?
 * When you compile the program, you will be under src directory. However, to execute the program, yoe
 * need to use `cd` command again to change to previous directory, project. Under project deirectory,
 * use `./build/bin/vis_sim <port_number>` to ececute. Then, to see the simulator, open a web browser,
 * and enter the address in your address bar, `http://127.0.0.1:<port_number>/web_graphics/project.html`.
 * 
 * \subsection observer_sec Designing and Implement the Observer Pattern
 * Observer Pattern mainly include two part. The first part is mainly responsible for update information
 * for bus data. Meanwhile, IObservable class is like a subject for IObserver to observe. So,
 * in order to let the IObserver to observe bus class, so bus class is turned into a derived class
 * of IObservable class.
 * \image html Observer_UML.png
 * \subsection discussion_sec How Bus Factory Can be Implemented?
 * Bus Factory can be implemented into two ways, abstract factory method and concrete bus factory.
 * Though concrete bus factory is implemented, I will discuss both methods in here.
 * - What are these two methods?
 * Abstract and concrete factory patterens are both able to do the same thingds, creating products.
 * However, abstract factory pattern creates famlilies instead of creating products like concrete
 * factory pattern. Here are two UML diagrams to show the structures of these two factory patterns.
 * Abstract Bus Factory
 * \image html AbstractBusFactory.png
 * Concrete Bus Factory
 * \image html ConcreteBusFactory.png
 * - Differences Between the Two Factory Patterns
 * 1. The first difference is what mentioned above, abstract factory pattern mainly create
 * sub-families which are responsible to create dependent productswhile concrete factory
 * pattern creates products.
 * 2. It is easy to understand the concrete factory pattern, it is a simple inheritance to
 * finish produce the products. However, abstract factory pattern composites.
 * - Pros Two Factory Patterns
 * The most distinguised benefits of useing a concrete factory is the simplicity. Because
 * one only needs to use on factory to produce multiple types of products, the code
 * designing phrase can save lots of time and efforts. However, based on the structure of
 * the abstract factory method, the products produced by each sub-families are more
 * compatible with each other. Meanwhile, because the factories are saperated into multiple
 * types, product creation codes can be extracted as well, so it is easier to expand or
 * support only one part of the code. New variants of products can be added easily.
 * - Cons of Two Factory Patterns
 * The cons of the two factories are each other's pros. Though it seems like abstract
 * factory pattern have many benefits, it is complicated to build a abstract factory,
 * which can be counted as con. However, the convenience brought many cons when
 * implementing concrete factory pattern. When you want to expand functionalities of
 * a single product, it is difficult to add into the code. Products and products are
 * less compatible.
 * - Pattern Chosen for the Project
 * This project uses concrete factory pattern. Because for this project, so far I do
 * not need to fulfill more functionality, in order to be simple, I chose to implement
 * concrete factory pattern.
 * 
 */

#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
#endif  // SRC_MAINPAGE_H_
