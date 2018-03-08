

- Comp15 Project1 Nozama. 
   Created by Xiaofei Guo, on Mar.2.2017

- This program does a simulation of an order processing facility for a top online retailer that we called Nozama Online.   
There is only one fetching unit and some positive number of packaging units.  
We determine which method should be used to assign orders to packaging units.  
The “SHORTEST_TIME” is defined by the sum of the “pack time remaining” of all orders in the queue.   
The”ROUND_ROBBIN” based on “taking turns”.

- Thanks to Bill_Yung.

- Order.h / Order.cppdefines Order struct and an overload operation”=“.   
  Orderqueue.h / Orderqueue.cpp defines Queue of orders.  
  ProcessQueue.h / ProcessQueue.cpp defines the queue of processed orders. This simulates the processing units.   
  PackageQueue.h /PackageQueue.cpp defines the queue of packaged orders.   
  Parser.h /Parser.cpp uses for reading from files.   
  Nozama.h / Nozama.cpp makes the data flow.   
  Main.cpp includes the processing of commands.    
  Makefile is for make file.
 
- compile via “make” command.

- I used 3 different classes framing 3 different queues. Queue is for protecting data. First is the orderqueue, it stores the data of orders’ info and make them a queue. Second is the processed queue. Orders are put in this queue and it will calculate the total processed time. Packagequeue is for processing user defined numbers of packing units and mode. Processed order queue is put in and then being “packaged”. Total processed time is returned.
Using queue can protect all the data from being mistaken or purposely modified.

