# Set implementation

## Task description
Implement the set type which contains integers. Represent the set as a sequence of its elements. Implement as methods: inserting an element, removing an element, returning whether the set is empty, returning whether the set contains an element, returning a random element without removing it from the set, returning the number of even numbers in the set (suggestion: store the number of even numbers and update it when the set changes), printing the set.

## Additional information of the task
Implement the types using ***classes***. Represent the types using sequences of same-type elements stored in ***vectors*** (vector<> in C++).

Create a main program with a ***menu*** to demonstrate the services (all the methods) a class provides in arbitrary order (based on the selections of the user). Make the main program instantiate an object of the class. The methods of the class can be called through the menu items. Print the state of the object either after the completion of each menu item or through another menu item for printing. If there are methods or friend functions that need multiple objects (like adding two matrices, for example), the main program should make it possible to create and print these objects through the menu.

Implement ***unit tests*** which should run automatically.

## Set of integers

`Set(n) = {a∈ℤⁿ, n∈ℕ | ∀i∈[1..n], ∀j∈[1..n] : i ≠ j → a[i] ≠ a[j]}`

## Operations on the set
### Inserting an element
-`insert(int e)`: Inserting an element to the end of the set if the element is not making any duplicates in the set.

This operation throws an exception if there exists an element from the set which is equal to the given inserting element `(∃i∈[1..n] : a[i] = e)`, otherwise the element should be inserted at the end of the set.

### Removing an element

-`remove(int e)`: Removing an element if the given element exists in the set. If it exists, the last (right-most) element at the end of the set shifts to the removed element’s index. 

This operation throws an exception if the want to be removed element does not exist in the set `∃i∈[1..n] : a[i] ≠ e`, otherwise the last element would shift to the want to be removed element’s index.

### Check if the set is empty

-`isEmpty()`: If the set is empty, the logical variable returns ‘true’, otherwise it would return ‘false’.

###	Check if the set contains an element

-`isIn(int e)`: Checking whether the set contains an element. If the element exists in the set, it stores the index of the element. If the element is not in the set, the logical exists variable sets to ‘false’, otherwise it sets to ‘true’ and stores the index of the element.

### Get a random element without removing from the set
-`rand_elem()`: Get a random element without removing it from the set. This operation throws an exception if the set is empty, otherwise a random element from the set would return. 

### The count of even numbers in the set.
-`getEvens()`: Returns the count of even numbers in the set. This operation returns number 0 if the set is empty or there is no even element in the set, otherwise the counter variable is increasing by 1 for every even element in the set.
