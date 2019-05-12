# My progress in fastai course - Lesson 5

#### Useful links:

1. [Video](https://course.fast.ai/videos/?lesson=5)
2. [Documentation collab](https://docs.fast.ai/collab.html)
4. [Lesson discussion thread](https://forums.fast.ai/t/lesson-5-in-class-discussion/30864)
5. [hiromis (GitHub)](https://github.com/hiromis/notes/blob/master/Lesson5.md)
6. [notes by PoonamV](https://forums.fast.ai/t/deep-learning-lesson-5-notes/31298)

#### Data set, which I used:

   * [Collab_filter.xlsx](https://github.com/fastai/course-v3/blob/master/files/xl/collab_filter.xlsx)

   Problem:  neural net from scratch.

#### My notes:

   - **Freezing** - don't back propagate the gradients back into those layers, so don't update those parameters;
   - **Discriminative learning rates** - in unfreezing; Using it with learning rate, because for the early layers is smaller, it's going to move them around less because we think they're already pretty good and also if it's already pretty good to the optimal value, if you used a higher learning rate, it could kick it out - it could actually make it worse which we really don't want to happen.
   - **affine functions** - 

#### Tips:

   1. **fit_one_cycle** - three kind of putting numbers in this function:
       * single number: e.g. 1e-3 -> every layer gets the same learning rate,
       * slice with single number e.g. slice(1e-3) -> the final layers get a learning rate of whatever you wrote down (1e-3), and then all the other layers get the same learning rate which is that divided by 3,
       * slice with two number: e.g. slice(1e-5, 1e-3) -> the first layer will get 1e-5, but final layer will get 1e-3 and the other layers will get learning rate that are equally spread between those two; 

#### Other resources:

   * [An overview of gradient descent optimization algorithms](http://ruder.io/optimizing-gradient-descent/)
   * [Netflix and Chill: Building a Recommendation System in Excel](https://towardsdatascience.com/netflix-and-chill-building-a-recommendation-system-in-excel-c69b33c914f4)
   * [Finally, a Machine That Can Finish Your Sentence](https://www.nytimes.com/2018/11/18/technology/artificial-intelligence-language.html)