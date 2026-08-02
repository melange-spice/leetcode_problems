# Shit I did wrong:
1. wtf is this bullshit bro: 

    ```cpp
    merged.push_back(nums2[0]);
    nums2.erase(nums2.begin()); //this fucker shifts the whole vector left each time erase()v wanks out the 0th element of a vector
    ```
2. I insert the smallest value in the most roundabout way possible by calcuting the difference:

```cpp
if (nums1.empty() == false)
            {
                difference1 = nums1[0] - merged.back();
            }

            if (nums2.empty() == false)
            {
                difference2 = nums2[0] - merged.back();
            }
```
3. Again the mistake of `1` is amplified in the loop during the construction of the merged array:

```cpp
if (nums2.empty() == false && nums1.empty() == false)
            {
                // smallest number goes to merged
                if (difference1 < difference2)
                {
                    merged.push_back(nums1[0]);
                    nums1.erase(nums1.begin());
                }
                else
                {
                    merged.push_back(nums2[0]);
                    nums2.erase(nums2.begin());
                }
            }
```

Should have just used seperate indexes for each of the array so you didn't have to shift the whole vector left.

4. I am dealing with the case of any of array being empty inside the loop: 
```cpp
 else if (nums1.empty() == false)
            {
                merged.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else if (nums2.empty() == false)
            {
                merged.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
```

While I could have done this more easily:
```cpp
 //dealing with the 1 remaining array if there is any left
        while (i < n1)
        {
            tmp.push_back(nums1[i]);
            i++;
        }
        while (j < n2)
        {
            tmp.push_back(nums2[j]);
            j++;
        }
```

5. One good thing I did was limit the number of times the loop to only about half of the array hence the merged array is smaller in size:
```cpp
for (int i = 0; i < combined / 2; i++)
```

## Each of the solutions above does not satisfy $O(\log (m+n))$ they have a linear time complexity of $O(n)$

Take into account how we first analyzed the mathematical properties of the system and then exploited those properties to divide the A+B array into two parts.

Now the divied A+B array can easy be processed via binary search.