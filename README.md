# FlowCloud support for MPIDE

This repo holds the changes required to let MPIDE compile and upload sketches that make use of 
[FlowCloud](http://flow.imgtec.com/developers/). 

Using these modifications applications using the Arduino environment can easily be developed to interact with the cloud. 

A tutorial and example project can be found on the [FlowCloud on Arduino blog](http://flowcloud.github.io/flow-on-arduino/).

This repository holds the source code of the modifications and additions to MPIDE, specifically MPIDE's `hardware` configuration. To use FlowCloud on supported boards (currently the WiFire), please download 
the zip file from the FlowCloud website as it contains some libraries that cannot be distributed on GitHub. For how to install this package follow the instructions on the [blog](http://flowcloud.github.io/flow-on-arduino/page2/).
