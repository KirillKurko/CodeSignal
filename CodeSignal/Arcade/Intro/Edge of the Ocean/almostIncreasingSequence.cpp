/*
Given a sequence of integers as an array, determine whether it is
possible to obtain a strictly increasing sequence by removing no
more than one element from the array.

Note: sequence a0, a1, ..., an is considered to be a strictly
increasing if a0 < a1 < ... < an. Sequence containing only one
element is also considered to be strictly increasing.

Example

For sequence = [1, 3, 2, 1], the output should be
almostIncreasingSequence(sequence) = false.

There is no one element in this array that can
be removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
almostIncreasingSequence(sequence) = true.

You can remove 3 from the array to get the strictly
increasing sequence [1, 2]. Alternately, you can remove
2 to get the strictly increasing sequence [1, 3].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer sequence

Guaranteed constraints:
2 ≤ sequence.length ≤ 105,
-105 ≤ sequence[i] ≤ 105.

[output] boolean

Return true if it is possible to remove one element
from the array in order to get a strictly increasing
sequence, otherwise return false.
*/

bool almostIncreasingSequence(std::vector<int> sequence) {
    int outOfOrderCount = 0, *comp = &sequence[0];
    for (size_t i = 1; i < sequence.size(); ++i) {
        if (sequence[i] > *comp) {
            comp = &sequence[i];
        }
        else {
            outOfOrderCount++;
            if (i - 2 >= 0) {
                comp = &sequence[i - 2];
                if (sequence[i] <= *comp) {
                    comp = &sequence[i - 1];
                    if (i + 1 < sequence.size()) {
                        if (sequence[i + 1] <= *comp) {
                            return false;
                        }
                    }
                }
            }
            comp = &sequence[i];
        }
    }
    return outOfOrderCount > 1 ? false : true;
}
