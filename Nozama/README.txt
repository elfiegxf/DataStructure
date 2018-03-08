{\rtf1\ansi\ansicpg1252\cocoartf1504\cocoasubrtf810
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww13580\viewh10620\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 1. Comp15 Project1 Nozama. \
   Created by Xiaofei Guo, on Mar.2.2017\
\
2. This program does a simulation of an order processing facility for a top online retailer that we called Nozama Online. There is only one fetching unit and some positive number of packaging units. We determine which method should be used to assign orders to packaging units. The \'93SHORTEST_TIME\'94 is defined by the sum of the \'93pack time remaining\'94 of all orders in the queue. The\'94ROUND_ROBBIN\'94 based on \'93taking turns\'94.\
\
3.Thanks to Bill_Yung.\
\
4.Order.h / Order.cppdefines Order struct and an overload operation\'94=\'93.\
  Orderqueue.h / Orderqueue.cpp defines Queue of orders.\
  ProcessQueue.h / ProcessQueue.cpp defines the queue of processed orders. This simulates the processing units.\
  PackageQueue.h /PackageQueue.cpp defines the queue of packaged orders.\
  Parser.h /Parser.cpp uses for reading from files.\
  Nozama.h / Nozama.cpp makes the data flow.\
  Main.cpp includes the processing of commands.\
  Makefile is for make file.\
 \
5.via \'93make\'94 command.\
\
6.I used 3 different classes framing 3 different queues. Queue is for protecting data. First is the orderqueue, it stores the data of orders\'92 info and make them a queue. Second is the processed queue. Orders are put in this queue and it will calculate the total processed time. Packagequeue is for processing user defined numbers of packing units and mode. Processed order queue is put in and then being \'93packaged\'94. Total processed time is returned.\
Using queue can protect all the data from being mistaken or purposely modified.\
\
7 I wrote a orderinfo.txt following the manual instruction input and the outcome is exactly same.}