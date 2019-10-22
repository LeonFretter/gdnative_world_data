A collection of systems, in which a world can be partitioned into
quantized, accessible elements.

# QuadrantField
Divides 2d-space into four quadrants.
These are: neg_neg, neg_pos, pos_neg, pos_pos (for x and y axes)
In each of those quadrants coordinates are considered positive.
This makes it easy to extend each of the quadrants with new elements, while
remaining able to efficiently access the elements via indices.