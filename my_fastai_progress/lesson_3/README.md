# My progress in fastai course - Lesson 3

#### Useful links:

1. [Video](https://course.fast.ai/videos/?lesson=3)
2. [Documentation - vision](https://docs.fast.ai/vision.html)
3. [Documentation - text](https://docs.fast.ai/text.html)
4. [Lesson discussion thread](https://forums.fast.ai/t/lesson-3-in-class-discussion/29733)
5. [hiromis (GitHub)](https://github.com/hiromis/notes/blob/master/Lesson3.md)


#### Data set, which I used:

   * [Planet: Understanding the Amazon from Space](https://www.kaggle.com/c/planet-understanding-the-amazon-from-space)
   * [CamVid](http://mi.eng.cam.ac.uk/research/projects/VideoRec/CamVid/)
   * [IMDB](http://ai.stanford.edu/~amaas/data/sentiment/)
   * [BIWI head pose](https://data.vision.ee.ethz.ch/cvl/gfanelli/head_pose/head_forest.html#db)

   
   Problem: multiclassification, segmentation, nlp, regression with image.

#### My notes:

   - [**vision.transform**](https://docs.fast.ai/vision.transform.html#List-of-transforms) - list of transform for data augumentation in fastai;
   - [**vision.data**](https://docs.fast.ai/vision.data.html) - function to get a DataBunch;
   - [**class DataBunch**](https://docs.fast.ai/basic_data.html#DataBunch) - A DataBunch is something which binds together a training data loader (train_dl) and a valid data loader (valid_dl);
   - An interesting points about:
       - **transform**:
           * for simple classificaton (dog vs cat): transforms by default will flip randomly each image, but they'll actually randomly only flip them horizontally. It is okey,
           * for classification for satellite imagery whether something's cloudy or hazy or whether there's a road there or not, could absolutely be flipped upside down;
       - **wrap** (innovation):
           * looking at the object from different perspective;
   - [**accuracy thresh**](https://docs.fast.ai/metrics.html#accuracy_thresh) - metrics from fastai;
   - [**SegmentationLabelList**](https://docs.fast.ai/vision.data.html#SegmentationItemList) - ItemList suitable for segmentation tasks;
   - [**to_fp16**](https://docs.fast.ai/basic_train.html#to_fp16) - trains model in 16-bit precision;
   - [**TextClasDataBunch**](https://docs.fast.ai/text.data.html#TextClasDataBunch) - create DataBunch from text;
   - [**language_model_learner**](https://docs.fast.ai/text.learner.html#language_model_learner) - create a Learner with a language model from data and arch;



#### Tips:

   1. **Progressive resizing** - we should deliberately make a lot of smaller datasets to step up from in tuning, because you can train much faster, it generalizes better (CV technic).
   2. **U-Net** - better than CNN for segmentation problems.
   3. Correctly classified pixels / total number of pixels - **accuracy mean for pixel wise segmentation**.
   4. **Mixed precision training** - it'll work about twice as fast as otherwise than casual approach, because it will use less GPU RAM. But you must have latest GPU for example RTX 2080 Ti from NVIDIA with latest drivers.
   5. **Tokenization** - it takes those words and converts them into a standard form of tokens (NLP technic).
   6. **Numericalization** - take a complete unique list of all of the possible tokens (NLP technic).
   7. If you’re using a pretrained model you need to use the same **stats** it was trained with.

#### Other resources:

   * [Links to different parts in video (author: melonkernel)](https://forums.fast.ai/t/lesson-3-links-to-different-parts-in-video/30077)
   * [Language model zoo](https://forums.fast.ai/t/language-model-zoo-gorilla/14623)
   * [U-Net](https://lmb.informatik.uni-freiburg.de/people/ronneber/u-net/)
   * [The data block API](https://docs.fast.ai/data_block.html)
   * [MoviePy](https://zulko.github.io/moviepy/)
   * [Neural Networks and Deep Learning - free online book](http://neuralnetworksanddeeplearning.com/)
   * [Cyclical Learning Rates for Training Neural Networks](https://arxiv.org/abs/1506.01186)
   * [Gradient descent from Coursera](https://www.coursera.org/lecture/neural-networks-deep-learning/gradient-descent-A0tBd?fbclid=IwAR08VsghxSsZnVEWLIZJdDhdzT-aM5L53cUnhibK0PK0O0KQT6MX5LuU8pc)
   * [Jeremy Howard interviews Leslie Smith](https://www.youtube.com/watch?v=dxpyg3mP_rU&feature=youtu.be)
   * [Activation functions](https://towardsdatascience.com/activation-functions-neural-networks-1cbd9f8d91d6)