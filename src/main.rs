fn main() //using the & operator. This is better becuase we can reference the array rather than send the whole array into the function
{
    let arry: [i32; 5] = [1,2,2,4,3]; //must populate array with values, declare the size and the data type.
    let sum = add_numbers(&arry); //add_numbers returns the sum of all the numbers
    println!("The sum of all the numbers is {}", sum);
}


fn add_numbers(arr: &[i32]) -> i32 //this declares the function needs a reference to an array. And it should return a int
{
    let mut total: i32 = 0; //initialise total
    for &num in arr
    {
        total = total + num;
    }
    total
}
