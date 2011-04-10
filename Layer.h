//
//  BrushLayer.h
//  TrenchBroom
//
//  Created by Kristian Duske on 10.04.11.
//  Copyright 2011 TU Berlin. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class RenderContext;

@protocol Layer <NSObject>

- (void)render:(RenderContext *)renderContext;

@end
