                            ECE GY 6193 Lab 2: Branch Prediction

NetID:ssv315



To simulate a correlating branch predictor that makes use of 2-bit saturating counters. We are provided with a text file containing a trace of branch instructions consisting of the PC at which each branch occurs, and whether the branch is Taken or Not Taken. 
Our goal is write code to evaluate the performance of a correlating branch predictor on this trace. Our output file indicates, for each branch in the trace, whether it was predicted as Taken or Not Taken. 

The trace file, trace.txt, contains one branch per line. Each line has the PC for the corresponding branch (in hex format) followed by a single bit indicating Taken (1) or Not Taken (0). A sample trace file is provided.  A sample trace file is provided.


Output Format:

The output from your simulator should be a file trace.out that has one line per branch. Each line has a single bit which indicates whether that branch was predicted as Taken (1) or Not Taken (0).



To compile : 
1.	In the terminal : g++ branchpredict.cpp

TO run :
1. In the terminal : ./a.out config.txt trace.txt
