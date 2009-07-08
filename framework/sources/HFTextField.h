//
//  HFTextField.h
//  HexFiend_2
//
//  Created by Peter Ammon on 2/2/08.
//  Copyright 2008 ridiculous_fish. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class HFLayoutRepresenter, HFRepresenter, HFController, HFHexTextRepresenter, HFStringEncodingTextRepresenter;

/*! @class HFTextField
    @brief A high-level view class that is analagous to NSTextField.
    
    HFTextField encapsulates a HFController and HFRepresenters into a single "do it all" NSControl analagous to NSTextField.  Its objectValue is an HFByteArray.  It sends its \c action to its \c target when the user hits return.  It has no control.
    
    An HFTextField can be configured to show a hexadecimal view, an ASCII (really the \c defaultCStringEncoding) view, or both.
    
    This class is currently missing a fair amount of functionality, such as enabled or editable state.
*/
    
@interface HFTextField : NSControl {
    HFController *dataController;
    HFLayoutRepresenter *layoutRepresenter;
    HFHexTextRepresenter *hexRepresenter;
    HFStringEncodingTextRepresenter *textRepresenter;
    IBOutlet id target;
    SEL action;
}

/*! Returns whether the hexadecimal view is shown. */
- (BOOL)usesHexArea;

/*! Sets whether the hexadecimal view is shown. */
- (void)setUsesHexArea:(BOOL)val;

/*! Returns whether the ASCII view is shown. */
- (BOOL)usesTextArea;

/*! Sets whether the ASCII view is shown. */
- (void)setUsesTextArea:(BOOL)val;

@end
