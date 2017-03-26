# Pixel Packing Data Transfer with TouchDesigner, openFrameworks, and Processing

Examples of sending data from OpenFrameworks and Processing to TouchDesigner via textures.

## Build and Version
These examples were written in Processing 3.2.1, openFrameworks v0.9.7 using Visual Studio 2015, and in 64-bit build 61480 of TouchDesigner088.

## Installation
### Processing :
This example requires the Spout for Processing 3rd Party library. To install this go to the ```Sketch``` menu, hover over ```Import Library...``` and click on ```Add Library...```  Search for 'Spout' in the ```Libraries``` search field, click on ```Spout for Processing``` by Lynn Jarvis and Martin Froelich. Click ```Install``` at the bottom.

### openFrameworks :
This example requires the ofxSpout library. The link to the [build used in the example is here](https://github.com/Mat-Loz/ofxSpout/tree/4cd68630c72e7f7fb1a1634fde1577fa5920ca14). 
After adding the ofxSpout folder to your addons, you'll need to update a few paths in your Visual Studio 2015 solution. For directions follow the steps described in [this Github Issue](https://github.com/Mat-Loz/ofxSpout/issues/1).

## Code
These examples demonstrate the use of bit-shifting to convert a single 32-bit value into a single RGBA pixel, then transfer the data through Spout to TouchDesigner. This is a useful technique for transmitting large amounts of data as Spout has a lower overhead than other protocols as the size of data becomes larger. Workflows become even more optimized when you're able to use the data in it's texture form in a shader without needing to convert it back into other data types on the CPU. 

For an indepth walkthrough see this post about [pixel packing on Elburz.io](http://elburz.io/pixel-packing).

The size of the texture sent over Spout is 16 x 4, which provides 3 rows of 16 pixels (X position, Y position, and diameter for each of the 12 balls). The texture size is then rounded up to nearest power of 2 for more efficient GPU processing.

### Processing Notes :
- The native Processing surface automatically multiplies the RGB values by the Alpha, so it requires the use of the ```PImage``` datatype to retain the RGB and A as seperate values.

### openFrameworks Notes :
- To keep the RGB values from being multiplied with the Alpha channel, make sure to include ```ofDisableAlphaBlending();```

### TouchDesigner Notes :
- A Crop TOP was added since openFrameworks sends a texture no smaller than 116 pixels wide.

## Attribution
- The code in both Processing and openFrameworks are the Bouncy Bubbles Processing example written by Keith Peters
- Spout example code used is in both Processing and openFrameworks examples was provided by the Spout libraries.
- Thanks to Derivative's support

If you use this in one of your projects, feel free to give us (nVoid) a shoutout or just let us know what you're up to! 
