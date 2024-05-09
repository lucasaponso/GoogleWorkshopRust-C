# Linux and Rust Google Workshop

## Rust Installation (Linux or WSL)
```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
. "$HOME/.cargo/env"
```

## Simple Main Function
The following example shows how to write a simple function that can print out some text using println!(). Rust searches for a main function to start the program from.

This is your basic print function in rust. (the exclamation point tells the compiler that it should be declared as a macro, more on that later.)
```
fn main() {
    println!("Hello World!");
}
```
## How to compile rust using rustc
Without compiler flags rust will create a binary file that has the same name as the source file.
```
rustc main.rs
```

To execute the binary
```
./main
```

## How to create, manage and compile rust using the cargo tool
To initialize the rust project, run the following command:
```
cargo new project-name
```

To compile a rust project, run the following command (you must be in the same directory as the project directory):
```
cargo build
```

To compile and execute the rust project, run the following command:
```
cargo run
```
How to format code so that it is easier to read and understand:
```
rustfmt filename
```

How to check if code is compilable without compiling it:
```
cargo check
```

## Project Breakdown

### src/
The following directory houses all the source files belonging to the project.

### Cargo.toml
Holds any dependecies that need to be included in the project.
### .gitignore
The following file retricts files and directories ability to be included in any git related actions.
### target/
The target directory holds all the binary information and executables




## Variables
To define a variable in rust we must include the let keyword to tell rust we would like to create a variable. Following the variable, we print the value of the variable using string formatters. This is similar to the C language where we use string formatters for printf, fprintf, etc.
```
fn main()
{
    let x = 4;
    !println("x is {}",x);
}

```
## Mutable Variables
To overwrite a variable in rust we need to use the mut keyword. Without this we run into an error. This ensures safety of the code so that the variable is not being overwritten accidentally by other moving parts within the code.

```
fn main()
{
    let mut x = 4;
    x = 5;
    !println("x is {}",x);
}
```
Note: Another way around this problem is to create the same variable after you declare it

For Example:
```
fn main()
{
    let x = 4;
    let x = 5;
    !println("x is {}",x);
}
```


## Explicit Type Declarations
To tell the compiler the exact type declaration for a given variable. We can use explicit type declarations. Before when we had been developing the compiler guessed the type. But if we want the compilter to know the exact type declaration for a given variable we must use it like this:

```
fn main()
{
    let x: i32 = 4;
    !println("x is {}",x);
}
```
or
```
fn main()
{
    let x: u8 = 4;
    !println("x is {}",x);
}
```
## Scopes
Within the rust ecosystem we can use scopes.
The following is considered a scope:
```
fn main()
{
    {
        let y: u8 = x;
    }
    let x: u8 = 4;
    !println("x is {}",x);
}
```
Lets dive into what this scope is doing:
- Inside the scope we are creating a variable named y that is set to the value of x. (Since they share the same type, this should work)
- The internal scope understands the external scope, but not the other way around.


## Constants
Constants are much like #defines in C. They are a constant variable that cannot be changed even if we where to use the mut keyword. We must also use explicit type declarations to ensure it follows the rust rules.
```
const SECONDS: u32 = 60;

fn main()
{
    !println("Number of seconds is {}",SECONDS);
}
```

## Tuples
Tuples are a data structure that can hold a number of objects regardless of whether they are different. This is how you can declare a tuple in rust:
```
fn main()
{
    let tup: (i32, bool, char) = (1, true, 's')
    !println("Number of seconds is {}",SECONDS);
}
```

We must declare the type for each element of the tuple. If the tuple cannot match with it's corresponding element then an error will be raised.

To print a element from the tuple, we can use this strategy:
```
fn main()
{
    let tup: (i32, bool, char) = (1, true, 's')
    println!("{}", tup.2)
}
```
This should print true.
Note: A tuple is not a dynamic data structure. You cannot add elements to the tuple after declaring it.


## Arrays
In rust an array is declared like this:
```
fn main()
{
    let arry: [i32; 5] = [1,2,2,4,3];
}

```
When declaring an array we must declare the type it contains and the number of elements it contains.

## Conditionals
In rust to write conditional statements is straightforward. This follows the same idea behind pythons system:
```
fn main() {
    let number = 6;

    if number % 2 == 0 {
        println!("Number is even!");
    } else if number % 3 == 0 {
        println!("Number is divisible by 3!");
    } else {
        println!("Number is neither even nor divisible by 3!");
    }
}

```

## Loops
In rust we write for loops like this:
```
for number in 1..=5 {
        println!("Number: {}", number);
    }
```
This strategy shows strong resembelence with the python for loop.


In rust we write while loops like this:
```
fn main() {
    let mut counter = 0;

    while counter < 5 {
        println!("Counter: {}", counter);
        counter += 1;
    }
}

```

## User Input
How do we retrieve input from stdin?
```
use std::io; // Import the std::io module

fn main() {
    println!("Please enter your name:");

    let mut input = String::new(); // Create a mutable variable to store the input

    // Read the input from the user and handle any errors
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");

    // Print the input provided by the user
    println!("Hello, {}", input);
}

```
What does all this mess mean?
- We first create a mutable variable we stores a string.
- We then use a crate named std::io, this crate allows us to retrieve input easily
- We provide a reference to the input variable
- We also add an expect, which acts like a exception raise
- Then we print the user input