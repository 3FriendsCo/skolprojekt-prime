Program
├── Preprocessor Directive: include <iostream>
├── Function Definition: main
│   ├── Variable Declaration: int a = 5
│   ├── Variable Declaration: int b = 7
│   ├── Function Call: add(a, b)
│   ├── Variable Declaration: int result = add(a, b)
│   ├── Function Call: std::cout << "Result is: " << result << std::endl
│   └── Return Statement
└── Function Definition: add
    ├── Function Parameter: int x
    ├── Function Parameter: int y
    ├── Variable Declaration: int result = x + y
    └── Return Statement: result

------------------ WITH CLASS -----------------------

Program
├── Preprocessor Directive: include <iostream>
├── Class Definition: circle
│   ├── Private:
│   │   ├── Variable Declaration: double radius
│   │   └── Variable Declaration: double pi = 3.14159
│   ├── Public:
│   │   ├── Constructor Definition: circle(double r)
│   │   │   └── Assign Statement: radius = r
│   │   └── Function Definition: double area()
│   │       └── Return Statement: pi * radius * radius
├── Function Definition: main
│   ├── Variable Declaration: circle myCircle(2.0)
│   ├── Variable Declaration: double circleArea = myCircle.area()
│   ├── Function Call: std::cout << "Area of circle is: " << circleArea << std::endl
│   └── Return Statement
└── Function Definition: add
    ├── Function Parameter: int x
    ├── Function Parameter: int y
    ├── Variable Declaration: int result = x + y
    └── Return Statement: result

