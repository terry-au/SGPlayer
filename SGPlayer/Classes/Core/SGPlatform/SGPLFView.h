//
//  SGPLFView.h
//  SGPlatform
//
//  Created by Single on 2017/2/24.
//  Copyright © 2017年 single. All rights reserved.
//

#import "SGPLFObject.h"
#import "SGPLFImage.h"
#import "SGPLFColor.h"

#if SGPLATFORM_TARGET_OS_MAC

typedef NSView SGPLFView;

#elif SGPLATFORM_TARGET_OS_IPHONE_OR_TV

typedef UIView SGPLFView;

#endif

NS_ASSUME_NONNULL_BEGIN

void SGPLFViewSetBackgroundColor(SGPLFView *view, SGPLFColor *color);
void SGPLFViewInsertSubview(SGPLFView *superView, SGPLFView *subView, NSInteger index);

SGPLFImage *_Nullable SGPLFViewGetCurrentSnapshot(SGPLFView *view);

NS_ASSUME_NONNULL_END
