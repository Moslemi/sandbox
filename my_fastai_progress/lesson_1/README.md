# My progress in fastai course - Lesson 1

#### Useful links:

1. [Video](https://course.fast.ai/videos/?lesson=1)
2. [Documentation](https://docs.fast.ai/vision.html)
3. [Lesson discussion thread](https://forums.fast.ai/t/lesson-1-discussion/27332)
4. [hiromis (GitHub)](https://github.com/hiromis/notes/blob/master/Lesson1.md)
5. [PoonamV (fastai forum)](https://forums.fast.ai/t/deep-learning-lesson-1-notes/27748)


#### Data set, which I used:

   * [Food-101](https://www.vision.ee.ethz.ch/datasets_extra/food-101/) - 101 food categories, with 101,000 images; 250 test images and 750 training images per class. The training images were not cleaned. All images were rescaled to have a maximum side length of 512 pixels.
   
   Problem: classification

#### My notes:

   - [**fastai.vision**](https://docs.fast.ai/vision.html) - module for computer vision;
   - **help()** - print out a quick little summary;
   - **doc()** - show documentation;
   - [**vision.learner**](https://docs.fast.ai/vision.learner.html) - a general concept for things that can learn to fit a model;
   - [**ConvLearner**](https://github.com/fastai/fastai/blob/master/old/fastai/conv_learner.py) - made convolutional neural network for you;
   - [**fit_one_cycle**](https://docs.fast.ai/train.html#fit_one_cycle) - better than simple fit (the 1cycle policy);
   - [**learner.save**](https://docs.fast.ai/vision.learner.html#create_cnn) - save weights from trained model;
   - [**data.c**](https://docs.fast.ai/vision.data.html#ImageDataBunch) - number of the classes in data;
   - [**ClassificationInterpretation**](https://docs.fast.ai/vision.learner.html#ClassificationInterpretation) - use this class for class interpretation, for example:
       - **plot_top_losses** - how good was your prediction;
       - **plot_confusion_matrix** - show the predicted and actual that got wrong most often in matrix;
       - **most_confused** - show the predicted and actual that got wrong most often;
   - [**learn.recorder.plot()**](https://docs.fast.ai/basic_train.html#Recorder.plot) - draw learning finder on plot (how quickly am I updating the parameters in model)

#### Tips:

   1. This is a shortcoming of current deep learning technology which is that a **GPU** has to apply the exact same instruction to a whole bunch of things at the same time in order to be fast. If the images are in different shapes and sizes, you can't do that.
   2. In fastai, everything you model with is going to be a **DataBunch** object. 
   3. Since our model is working as we expect it to, we will **unfreeze** our model and train some more.
   4. A good rule of thumb is after you unfreeze (i.e. train the whole thing), pass a max learning rate parameter, pass it a slice, make the second part of that slice about **10 times smaller** than your first stage.

#### Other resources:

   * [The 1cycle policy](https://sgugger.github.io/the-1cycle-policy.html)
   * [Normalization](https://stats.stackexchange.com/questions/211436/why-normalize-images-by-subtracting-datasets-image-mean-instead-of-the-current)
   * [ResNet paper](https://arxiv.org/pdf/1512.03385.pdf)
   * [Food-101 paper](https://www.vision.ee.ethz.ch/datasets_extra/food-101/static/bossard_eccv14_food-101.pdf)