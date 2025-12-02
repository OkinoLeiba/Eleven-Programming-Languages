from typing import TypedDict

class PythonWork():
    def __init__(self, arguments: dict) -> None:
        self.hello = "Hello World!"
        self.combArray = arguments['combArray']
        self.combinResult = 1
        
        self.north = arguments['north']
        self.east = arguments['east']
        self.south = arguments['south']
        self.west = arguments['west']
    
        
    
    def helloWorld(self) -> str:
        print("Hello World!")
        print(self.hello)
        return self.hello 
    
    def combination(self) -> int:
        for n in self.combArray:
            self.combinResult *= n
        print(self.combinResult)
        return self.combinResult
    
    def trackRobot(self, n: int = 0, w: int = 0, s: int = 0, e: int = 0) -> list:
        l: int = 0
        r: int = 0
        
        l = n + (s * -1)
        r = w + (e * -1)
        
        robotResult = [l, r]
        
        print(robotResult)
        return robotResult
        
    def reverse_list(self, head: list) -> list:
        curr = head
        prev = None
        currList = iter(curr)
        while curr:
            next_node = next(currList)
            next(currList) = prev
            prev = curr
            curr = next_node 
            
            return prev  
        
    # Given an array of positive and negative numbers, write a function that returns the two highest numbers in ascending order. 
    # You may not use sort in this challenge or any built in function like max.
    # Input: [-4,22,87,-34,13,76,-2,-6,9,10]
    # Output: [76, 87]


    def highest_number(arr):
        sort_arr = []
        max_val = 0
        max_val1 = 0
        max_val2 = 0
        
        for i, n in enumerate(arr):
            if i < len(arr) - 1 and n > arr[i+1] :
                sort_arr.append(n)
        return sort_arr[0:2]

        for i, n in enumerate(arr):
            if n > max_val1:
                max_val1 = n
        for i, n in enumerate(arr):
            if  max_val1 != max_val2 and n > max_val2:
                max_val2 = n
        return [max_val1, max_val2]
    
            



    # Given a string s, reverse the order of characters in each word 
    # within a sentence while still preserving whitespace and initial word order.
    # Input: "Hello World"
    # Output: "olleH dlroW"
    # Input: "A quick brown fox jumps over the lazy dog"
    # Output: "A kciuq nworb xof spmuj revo eht yzal god"
    
    def reverse_string(s):
        new_string = s.split(" ")
        result = ""
        
        
        for j, w in enumerate(new_string):
            for i, l in enumerate(w):
                result += w[len(w) - i - 1]
            if (j != len(new_string) - 1):
                result += " "
        return result
        



            
    
     


# main entry point for program
Arguments = TypedDict('Arguments', 
                      {'combArray': list,
                       'north': int, 
                       'east': int,
                       'south': int,
                       "west": int})

arguments: Arguments = {
    'combArray': [2, 3, 4, 5],
    'north': 0,
    'east': 0,
    'south': 0,
    'west': 0,
    
}
pythonWork = PythonWork(arguments) 


pythonWork.helloWorld()

pythonWork.combination()

pythonWork.trackRobot(-20, 10, 20)

pythonWork.reverse_list([2, 3, 4, 5])

pythonWork.highest_number([-4,22,87,-34,13,76,-2,-6,9,10])

pythonWork.reverse_string("A quick brown fox jumps over the lazy dog")
        