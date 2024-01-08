# Machine Learning Project with Neural Networks

The project explores the domain of machine learning through the implementation of neural networks. The project consists of two key examples.

---

## Example 1: Simplest neural network (Perceptron)

The first example introduces the perceptron, the simplest neural network with a single neuron. This network enables the recognition of simple patterns, such as connections between sets of numbers. Visualizations before and after the learning process clearly demonstrate how the model adapts over time.

![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/260ce590-f998-469b-b528-65eb19529eeb)

The goal is for the perceptron to learn the connection between the first set (0,1,2,3,4,5) and the second set (0,2,4,6,8,10), which is essentially multiplying by 2 (and adding nothing).


### Before training:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/511af133-9098-453d-b4ae-da5d57db65c0)


As seen, initially, the model multiplies by 3.91 and adds -0.14. Consequently, its predictions are incorrect.

### After training:
![Nakon učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/8ce682d9-60f9-4058-8b9b-f4fd6e7a3728)

During the learning process, the model reduces the values from 3.91 to 2 and -0.14 to 0. 

This is achieved through the Cost function, and the entire goal of the learning process is to minimize the Cost function value, adjusting parameters and improving the model's predictions.


### Cost function:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4efabe17-a8fc-4376-8e7d-e4dee064392c)


---

## Example 2: More Complex Neural Network with more Neurons (Truth tables)

The second example involves connecting multiple neurons to create a more intelligent system.

### Model Structure:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/cedc50fb-1493-4fe6-addc-d38209e8e596)

This model, with three connected neurons, demonstrates the ability to recognize more complex patterns and rules, such as truth tables (XOR).

### XOR Truth Table:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4eac1bea-4556-4c04-9f6e-3499b13a96b6)

As seen in the table, the model must accurately predict the output value (0/1) when given two inputs (e.g., 0 and 0).

### Before training:
![Prije učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/4494c54c-f61a-4a68-b043-b6fe0335bbd6)

### After training:
![Nakon učenja](https://github.com/AnteDev00/Machine-Learning/assets/151842550/7a37a789-9743-4d13-9013-e914ae231e80)

This model controls a total of nine values, and after the training process, predictions become more precise. 

It involves more complex Cost and Forward functions to achieve this.

### Cost and Forward functions:
![image](https://github.com/AnteDev00/Machine-Learning/assets/151842550/14fac635-2a2c-4bf7-91f4-e4ed80c78dde)


--- 
