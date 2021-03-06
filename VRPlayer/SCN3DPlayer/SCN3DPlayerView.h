//
//  SCN3DPlayerView.h
//  播放器渲染，将图像显示在不同的模型上面
//
//  Created by tat on 16/8/23.
//  Copyright © 2016年 tat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SceneKit/SceneKit.h>
#import <GLKit/GLKit.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef NS_ENUM(NSInteger, SCN3DInteractive) {
    SCN3DInteractiveTouch,   // 触摸
    SCN3DInteractiveMotion,  // 重力感应
    SCN3DInteractiveMotionAndTouch,  // 两者皆有
};

typedef NS_ENUM(NSUInteger, SCN3DDisplayMode) {
    SCN3DDisplayModePlaneNormal,  // 普通模式
    SCN3DDisplayModePlaneSlide,   // 平面180模式
    SCN3DDisplayModeShapeTube,    // 圆柱模式
    SCN3DDisplayModeShapeBall,    // 球形模式
    SCN3DDisplayModeVR360Full,    // VR全景模式
    SCN3DDisplayModeVRGlasses,    // VR眼镜模式
    SCN3DDisplayModeVRPlanet,     // VR小行星模式
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////

@interface SCN3DPlayerView : UIView

@property (strong, nonatomic) SCNScene *scene;  // 场景
@property (strong, nonatomic) SCNView  *scViewLeft;   // 左视图，用于VR眼镜模式
@property (strong, nonatomic) SCNView  *scViewRight;  // 右视图，用于VR眼镜模式
@property (strong, nonatomic) SCNNode  *shapeNode;    // 形状节点
@property (strong, nonatomic) SCNNode  *cameraNode;   // 摄像机节点

//_________________________________________________________________________________________________

/// 设置交互模式
- (void)setInteractiveMode:(SCN3DInteractive)interactive;
/// 设置视频播放模式
- (void)setVideoDisplayMode:(SCN3DDisplayMode)displayMode;
/// 设置视频交互支持的滑动方向，默认关闭
- (void)setHorizontalEnabled:(BOOL)horEnabled verticalEnabled:(BOOL)verEnabled;
/// 设置是否开启重力感应，默认关闭
- (void)setGSensorMotionEnabled:(BOOL)GSensorEnabled;
/// 设置是否开启缩放，默认关闭
- (void)setPinchScaleEnabled:(BOOL)pinchEnabled;
/// 设置最小缩放值、最大缩放值，默认1.0~2.0
- (void)setMinScale:(float)minScale maxScale:(float)maxScale;
/// 设置垂直视差角度，默认-90~90
- (void)setVerticalMinRotate:(float)minRotate maxRotate:(float)maxRotate;
/// 设置纹理坐标偏移
- (void)setTextureOffsetX:(float)x offsetY:(float)y;
/// 设置纹理坐标缩放
- (void)setTextureScaleX:(float)x ScaleY:(float)y;

//_________________________________________________________________________________________________

/// 设置视频源宽高比
- (void)setVideoAspectRatio:(float)aspectRatio;
/// 设置当前视图横竖屏方向
- (void)setCurrentOrientation:(UIInterfaceOrientation)orientation;
/// 设置当前缩放值
- (void)setCurrentScale:(float)curScale;
/// 设置当前视差角度
- (void)setCurrentRotateX:(float)rotateX rotateY:(float)rotateY;

//_________________________________________________________________________________________________

/// 设置帧视频图像，用来渲染视频
- (void)setFramesPerVideoImage:(UIImage *)image;

@end
