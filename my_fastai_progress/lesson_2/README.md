# My progress in fastai course - Lesson 2

#### Useful links:

1. [Video](https://course.fast.ai/videos/?lesson=2)
2. [Documentation](https://docs.fast.ai/vision.html)
3. [Lesson discussion thread](https://forums.fast.ai/t/lesson-2-chat/28722)
4. [hiromis (GitHub)](https://github.com/hiromis/notes/blob/master/Lesson2.md)


#### Data set, which I used:

   * My dataset, which I made. Go to [Google Images](http://images.google.com) and search for the images I am interested in. :-)
   
   * Script, which I use to download urls:
   ```javascript
urls = Array.from(document.querySelectorAll('.rg_di .rg_meta')).map(el=>JSON.parse(el.textContent).ou);
window.open('data:text/csv;charset=utf-8,' + escape(urls.join('\n')));
```

   
   Problem: classification

#### My notes:

   - [**verify_image**](https://docs.fast.ai/vision.data.html#verify_images) - check if the image in path are not broken;
   - [**ImageCleaner**](https://docs.fast.ai/widgets.image_cleaner.html#ImageCleaner) - displays images for relabeling or deletion and saves changes in path as 'cleaned.csv';
   - [**ImageDataBunch.from_folder**](https://github.com/fastai/fastai/blob/master/fastai/vision/data.py#L134) - create from a csv file in path/csv_labels;
   - [**DatasetFormater().from_toplosses()**](https://docs.fast.ai/widgets.image_cleaner.html#DatasetFormatter.from_toplosses) - gets indices with top losses;
   - [**.from_similars()**](https://docs.fast.ai/widgets.image_cleaner.html#DatasetFormatter.from_similars) - gets the indices for the most similar images;

#### Tips:

   1. On video Jeremy shown **FileDeleter**, but now FileDeleter was **removed** in favor of two new widgets: **ImageDeleter** and **ImageRelabeler**. ImageDeleter is essentially the same as the old FileDeleter.
   2. Notice that the widget will **not delete images directly from disk** but it will create a new csv file **cleaned.csv** from where I can create a new ImageDataBunch with the corrected labels to continue training my model.
   3. In production's predictions, it is better to use CPU than GPU, because it is cheaper and can do the prediction of single data when GPU needs to wait for a full batch of data.
   4. When learning rate is big, valid loss is big too.
   5. If your learning rate is too small is that your training loss will be higher than your validation loss. You never want a model where your training loss is higher than your validation loss. That always means you haven't fitted enough which means either your learning rate is too low or your number of epochs is too low.
   6. Any morel that is trained correctly will always have train loss lower than validation loss. That is not a sign of overfitting.

#### Other resources:

   * [FileDeleter was removed (author: zachcaceres)](https://forums.fast.ai/t/lesson-2-further-discussion/28706/61)
   * [Tool for deleting files on the Google Image Search page before downloading](https://forums.fast.ai/t/tool-for-deleting-files-on-the-google-image-search-page-before-downloading/28900)
   * [How (and why) to create a good validation set](https://www.fast.ai/2017/11/13/validation-sets/)
   * [SSG](https://en.wikipedia.org/wiki/Stochastic_gradient_descent)