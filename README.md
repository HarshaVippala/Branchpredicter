# Branch Predictor Simulator

## Overview
This project implements a correlating branch predictor simulator that uses 2-bit saturating counters. The simulator evaluates the performance of branch prediction techniques on a trace of branch instructions, which is crucial for modern CPU performance optimization.

## Background
Branch prediction is a critical component in modern CPU design that attempts to guess the outcome of a branch instruction before it is executed. Effective branch prediction reduces pipeline stalls and improves overall CPU performance. This project focuses on implementing and evaluating a correlating branch predictor with 2-bit saturating counters.

## Project Description
The simulator takes a trace file containing branch instructions with their program counters (PCs) and actual outcomes (Taken/Not Taken). It then predicts whether each branch will be taken or not taken based on the implemented prediction algorithm, and outputs these predictions to a file.

## Implementation Details
- **Prediction Algorithm**: Correlating branch predictor with 2-bit saturating counters
- **Input**: Trace file with branch PCs and actual outcomes
- **Output**: Predictions for each branch (Taken/Not Taken)

## File Structure
- `branchpredict.cpp`: Main implementation of the branch predictor
- `config.txt`: Configuration parameters for the predictor
- `trace.txt`: Sample trace file with branch instructions
- `readMe.txt`: Original documentation

## How to Use

### Compilation
```bash
g++ branchpredict.cpp
```

### Execution
```bash
./a.out config.txt trace.txt
```

### Input Format
The trace file (`trace.txt`) contains one branch per line, with each line having:
- PC for the corresponding branch (in hex format)
- A single bit indicating Taken (1) or Not Taken (0)

### Output Format
The output file (`trace.out`) contains one line per branch, with each line having a single bit indicating whether that branch was predicted as Taken (1) or Not Taken (0).

## Performance Evaluation
The effectiveness of the branch predictor can be measured by comparing the predicted outcomes with the actual outcomes in the trace file. A higher match rate indicates better prediction accuracy.

## Applications
Branch prediction is essential in:
- CPU design and optimization
- Performance analysis of processor architectures
- Computer architecture research and education

## Technologies Used
- C++
- Branch prediction algorithms
- Computer architecture concepts