---
tags:
  - 代码
---
# 1 基本介绍与粗略感受
**基本介绍** 
- Manim 的全称是 Mathematical Animation，是由 Grant Sanderson (3b1b) 开发的一款基于 Python 代码的数学动画软件。
- Manim 提供了很多数学中的常用的物件，比如数轴、参数方程曲线、向量、坐标平面等。
- Manim 没有图形化界面，只能使用写代码的方式制作动画。跟常见的图形化界面动画软件（如 PPT、AE）相比，工作方式有很大不同。
- Manim 是基于 Python 代码的软件，这意味着你必须要有一定的 Python 基础（尤其是关于类/面向对象的基础）
- 想要安装 Manim，首先要安装 Python。在安装 Python 时，强烈建议先安装 mamba/conda 和 vscode，可以为你带来极大的便利。

**命令行参数** 
如：`manim try.py -p` 
- 文件路径（如 try.py）：渲染该文件中的 Scene
- -p（即 preview）：预览，即渲染完成后打开文件
- 也可以在文件路径后加上类名，精准匹配需要渲染的 Scene，如 `manim try.py Try -p` 
Manim 命令参数十分丰富。

**Scene、Animation 与 Mobject** 
这是 Manim 中最常用的三大类：
- **Scene**：给动画提供一个播放场景。
- **Mobject**：场景中的各种物体，如圆形、方形等。
- **Animation**：作用在 Mobject 之上，用这些物体制作一些动画。
示例：
```Python
from manim import * # 引入了 Manim 包
class Try(Scene): # 定义了继承自 Scene 的类
    def construct(self): # 并给它定义了 construct 方法
        c = Circle(fill_opacity=1) # 定义了一个圆，内部填充的不透明度设置为 1（完全不透明）
        s = Square(color=YELLOW, fill_opacity=1) # 定义了一个正方形，颜色为黄色，不透明度为 1
        self.play(FadeIn(c)) #把圆形 c 以淡入的形式添加到场景中
        self.wait() # 让动画画面等待一秒钟
        self.play(ReplacementTransform(c, s)) # 把 c 转化成 s
        self.wait() # 等待 1 秒
        self.play(FadeOut(s)) # 把 s 淡出
        self.wait() # 等待 1 秒
```
1. Scene 四个最常用方法：add、remove、play、wait
    1. add 和 remove 是针对 Mobject 的，可以从一个场景中添加或者移除一个或多个 Mobject，如：
	    ```Python
        self.add(c, s)
        self.remove(c)
        ```
    1. play 是针对 Animation 的，可以播放一个或多个动画，如果给一个 play 方法传入多个 Animation 的话，它会同时播放这些动画，如：
        ```Python
        self.play(FadeIn(c))
        self.play(FadeOut(c), FadeIn(s))
        ```
    3. wait 可以让画面等待一段时间，如果不传入任何参数，默认等待 1 秒，如：
        ```Python
        self.wait()
        self.wait(0.2)
        ```
2. Animation 类：FadeIn、ReplacementTransform、FadeOut 等，它们都作用于一个或多个 Mobject 之上，然后传入 Scene 对象的 play 方法进行播放。通过控制它们的参数，也可以实现一些更为复杂的效果。
3. Mobject 类：包罗万象，十分多样。
Manim 动画的制作，主要是通过 Mobject 和 Animation 的操作来实现的。
# 2 Manim 基本图形
## 2-1 点
**点** 
绘制任意其他一个图形，都是用点来定位的。
按照 $3 \times 3$ 的格式绘制 9 个点：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        for x in range(-1, 2):
            for y in range(1, -2, -1):
                p =  Dot([x, y, 0])
                self.play(Create(p), run_time = 0.5)
```
## 2-2 线
**线** 
Manim 的线都是线段，绘制线只需要提供两个点的坐标。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._lines()
        self.wait()

    def _lines(self):
        l = Line([-1, 1, 0], [1, 1, 0]) # 直线
        self.play(Create(l), run_time = 0.5)
        a = Arrow([-1, 0, 0], [1, 0, 0])
        self.play(Create(a), run_time = 0.5) # 带箭头的线
        dl = DashedLine([-1, -1, 0], [1, -1, 0])
        self.play(Create(dl), run_time = 0.5) # 虚线
```
## 2-3 圆
**圆**
只需要提供半径即可，圆心默认在屏幕的中心：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._circles()
        self.wait()
    
    def _circles(self):
        c = Circle(radius = 1)
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 2)
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 3)
        self.play(Create(c), run_time = 0.5)
```

**椭圆**
绘制椭圆的两个参数 width 和 height 分别控制椭圆的最大宽度和最大高度。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._ellipses()
        self.wait()
    
    def _ellipses(self):
        e = Ellipse(width = 1, height = 0.5)
        self.play(Create(e), run_time = 0.5)
        e = Ellipse(height = 4, width = 1.5)
        self.play(Create(e), run_time = 0.5)
        e = Ellipse(width = 8, height = 5)
        self.play(Create(e), run_time = 0.5)
```

**圆弧** 
三个参数：
- angle：圆弧的弧度
- start_angle：开始的角度，默认 0
- radius：圆弧的半径
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._arcs()
        self.wait()
    
    def _arcs(self):
        # 90 度圆弧，半径 1
        a = Arc(angle = PI / 2, radius = 1)
        self.play(Create(a), run_time = 0.5)
        # 180 度圆弧，半径 2
        a = Arc(angle = PI, radius = 2)
        self.play(Create(a), run_time = 0.5)
        # 30 度圆弧，半径 2，从 270 度开始绘制
        a = Arc(angle = PI / 6, start_angle = PI * 1.5, radius = 2)
        self.play(Create(a), run_time = 0.5)
```
## 2-4 多边形
### 2-4-1 等边三角形
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._triangles()
        self.wait()
    
    def _triangles(self):
        t = Triangle()
        self.play(Create(t))
```
### 2-4-2 各种矩形
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._squares()
        self.wait()
    
    def _squares(self):
        s = Square(side_length = 1) # 正方形
        self.play(Create(s), run_time = 0.5)
        r = Rectangle(width = 4, height = 3) # 矩形
        self.play(Create(r), run_time = 0.5)
        r = RoundedRectangle(corner_radius = 0.6, width = 6, height = 5) # 圆角矩形
        self.play(Create(r), run_time = 0.5)
```
### 2-4-3 任意多边形
通用的`Polygon`对象，它会依次连接传入的坐标点列表，绘制任意多边形。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._polygons()
        self.wait()
    
    def _polygons(self):
        p = Polygon([-3, 1, 0], [-1, 1, 0], [-2, -1, 0])
        self.play(Create(p), run_time = 0.5)
        p = Polygon([1, 1, 0], [2, 0, 0], [3, 1, 0], [3, -1, 0], [1, -1, 0])
        self.play(Create(p), run_time = 0.5)
```
### 2-4-4 正多边形
利用`Polygon`绘制正多边形理论上是完全可行的。不过，要自己去计算各个正多边形的坐标点显然有些费时费力，所以，`manim`中还提供了一个专门用来绘制正多边形的对象 `RegularPolygon`.

```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._regular_polygons()
        self.wait()
    
    def _regular_polygons(self):
        p1 = RegularPolygon(n = 6) # 正六边形
        p2 = RegularPolygon(n = 8) # 正八边形
        p3 = RegularPolygon(n = 10) # 正十边形

        vg = VGroup(p1, p2, p3)
        vg.arrange(RIGHT, buff = SMALL_BUFF)
        self.play(Create(vg))
```
# 3 Manim 图形样式
绘制图形时，还有一些可选参数，不填的话会按默认样式输出。
控制图形样式的参数最常用的有以下四个：
1. stroke_width：图形边框的粗细
2. color：图形的颜色
3. fill_color：图形的填充色
4. fill_opcacity：填充色的透明度，这个参数一般和 `fill_color` 一起使用。
## 3-1 边框
线、圆和多边形都可以通过 `stroke_width` 调整边框粗细程度。
**线的边框**
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._lines()
        self.wait()

    def _lines(self):
        l = Line([-1, 1, 0], [1, 1, 0], stroke_width = 1) # 直线
        self.play(Create(l), run_time = 0.5)
        a = Arrow([-1, 0, 0], [1, 0, 0], stroke_width = 5)
        self.play(Create(a), run_time = 0.5) # 带箭头的线
        dl = DashedLine([-1, -1, 0], [1, -1, 0], stroke_width = 10)
        self.play(Create(dl), run_time = 0.5) # 虚线
```

**圆的边框**
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._circles()
        self.wait()
    
    def _circles(self):
        c = Circle(radius = 0.8, stroke_width = 1).shift(LEFT * 2)
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 0.8, stroke_width = 5)
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 0.8, stroke_width = 10).shift(RIGHT * 2)
        self.play(Create(c), run_time = 0.5)
```

**多边形的边框**
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._polygons()
        self.wait()
    
    def _polygons(self):
        p = Polygon([-3, 1, 0], [-1, 1, 0], [-2, -1, 0], stroke_width = 5)
        self.play(Create(p), run_time = 0.5)
        p = Polygon([1, 1, 0], [2, 0, 0], [3, 1, 0], [3, -1, 0], [1, -1, 0], stroke_width = 10)
        self.play(Create(p), run_time = 0.5)
```

## 3-2 颜色
各种基本图形本身有默认的颜色，比如**线**默认是白色，**圆**默认红色，**多边形**默认蓝色等。 除了默认颜色，`manim`还预置了一系列的颜色，可以直接按颜色的名称来使用。
![](https://rcndb0nxsbc2.feishu.cn/space/api/box/stream/download/asynccode/?code=MDc4MGY0ZjQ0NmJmMzNhMGI4MDNiMWIwOWFiZjZlYzVfVG0xNkUxUU1EcFZPSzdCZ2cxYVRNSE9zOTM5WWxzdVlfVG9rZW46UVlqTGJMR3ZOb202YjR4c1U1emNlZVkwblE2XzE3MzUxMTcxODA6MTczNTEyMDc4MF9WNA)
设置图形的颜色，使用 `color`属性。
为了节省篇章，只拿线的颜色举例子，对于圆、多边形等同理。

**线的颜色**
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._lines()
        self.wait()

    def _lines(self):
        l = Line([-1, 1, 0], [1, 1, 0], stroke_width = 1, color = RED) # 直线
        self.play(Create(l), run_time = 0.5)
        a = Arrow([-1, 0, 0], [1, 0, 0], stroke_width = 5, color = YELLOW)
        self.play(Create(a), run_time = 0.5) # 带箭头的线
        dl = DashedLine([-1, -1, 0], [1, -1, 0], stroke_width = 10, color = GREEN)
        self.play(Create(dl), run_time = 0.5) # 虚线
```
## 3-3 填充
最后是填充色，关联两个属性：`fill_color`和 `fill_opacity`。 这两个属性一般用在闭合的图形中，比如圆和多边形。
为了节省篇章，只拿圆的填充举例子，对于多边形等同理

**圆的填充**
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._circles()
        self.wait()
    
    def _circles(self):
        c = Circle(radius = 0.8, 
                   stroke_width = 1, 
                   color = RED, 
                   fill_color = YELLOW, 
                   fill_opacity = 0.5
                   ).shift(LEFT * 2)
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 0.8, 
                   stroke_width = 5, 
                   color = YELLOW, 
                   fill_color = GREEN, 
                   fill_opacity = 0.2
                   )
        self.play(Create(c), run_time = 0.5)
        c = Circle(radius = 0.8, 
                   stroke_width = 10, 
                   color = GREEN, 
                   fill_color = RED, 
                   fill_opacity = 0.8).shift(RIGHT * 2)
        self.play(Create(c), run_time = 0.5)
```
# 4 文字和公式
`manim`中提供了两种方式来表示文字信息，一种是 `Text`系列，一种是 `Tex`系列。 `Text`系列在显示文字信息方面，提供了更多的的属性来调整显示效果。如果有大段的文字要排版，或者对文字的显示效果要求高的话，建议使用 `Text`。
而 `Tex`系列最大的优势是支持 `Latex`，也就是说它能更好的显示数学公式。
`Tex`目前还不支持显示中文，如果一段文本中既有中文又有数学公式的话，需要结合 `Text`和 `Tex`一起来显示。
## 4-1 Text
### 4-1-1 一般文本
一般文本 `Text`支持显示任何语言：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._text()
        self.wait()
    
    def _text(self):
        tx1 = Text("hello world").shift(UP * 2)  # 英文
        self.play(Write(tx1), run_time = 1)
        tx2 = Text("你好，世界").shift(UP)    # 中文
        self.play(Write(tx2), run_time = 1)
        tx3 = Text("こんにちは世界") # 日文
        self.play(Write(tx3), run_time = 1)
        tx4 = Text("Привет, мир").shift(DOWN)   # 俄文
        self.play(Create(tx4), run_time = 1)
        tx5 = Text("مرحبا بالعالم", font="sans-serif").shift(DOWN * 2) # 阿拉伯文
        self.play(Write(tx5), run_time = 1)
```
### 4-1-2 段落文本
段落文本 `Paragraph`可以多行文本进行简单的排版：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._text()
        self.wait()
    
    def _text(self):
        paragraph = Paragraph(
            "   春晓\n",
            "春眠不觉晓",
            "处处闻啼鸟",
            "夜来风雨声",
            "花落知多少",
        )
        self.play(Write(paragraph), run_time = 5)
```
### 4-1-3 带标记的文本
带标记的文本`MarkupText`类似`HTML`，可以像 word 那样提供一些标记文本的功能。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._text()
        self.wait()
    
    def _text(self):
        tx = MarkupText("<b>bold</b> <i>斜体文字</i>").shift(UP * 1.5)
        self.play(Write(tx), run_time = 1)
        tx = MarkupText("<u>下划线</u> <s>中划线</s>").shift(UP * 0.5)
        self.play(Write(tx), run_time = 1)
        tx = MarkupText('<span underline="double">双下划线</span> <span underline="error">错误标记</span>').shift(DOWN * 0.5)
        self.play(Write(tx), run_time = 1)
        tx = MarkupText("下标和上标：H<sub>2</sub>O H<sub>3</sub>O<sup>+</sup>").shift(DOWN * 1.5)
        self.play(Write(tx), run_time = 1)
```
## 4-2 Tex
`Tex` 系列的对象主要是用来显示数学公式。
基于`Tex` 之上，`manim` 还封装了**列表**和**标题**两种常用的对象。 不过，`Tex`默认只支持显示英文，所以多用于显示公式，显示文本还是 `Text` 系列的对象比较常用。
### 4-2-1 数学公式
`Tex`可以显示任何 `Latex`格式的数学公式：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._tex()
        self.wait()
    
    def _tex(self):
        tx = Tex(r"$a^2 + b^2 = c^2$").shift(UP)
        self.play(Write(tx), run_time = 1)
        tx = Tex(r"$E = mc^2$")
        self.play(Write(tx), run_time = 1)
        tx = Tex(r"$e^{i\pi} + 1 = 0$").shift(DOWN)
        self.play(Write(tx), run_time = 1)
```
### 4-2-2 列表文本
`BulletedList`会将传入的多个字符串以列表的方式排列起来：
```Python
from manim import *
class Try(Scene):
    def construct(self):
        self._tex()
        self.wait()
    
    def _tex(self):
        tx = BulletedList("$a^2 + b^2 = c^2$", "$E = mc^2$", "$e^{i\pi} + 1 = 0$")
        self.play(Write(tx), run_time = 3)
```
### 4-2-3 标题
`Title`自动显示在顶部，它和 `BulletedList`一样，都是为了减轻排版的负担。
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._tex()
        self.wait()
    
    def _tex(self):
        tx = Title(f"Manim version {manim.__version__}")
        self.play(Write(tx), run_time = 3)
```
# 5 文本样式
文本的样式主要指**颜色**和**字体**相关的属性设置。
对于`manim`的两个文本对象 `Text`和 `Tex`来说，`Text`对象有更多的属性可以调整样式。相对来说，由于 `Tex`主要用来显示数学公式，所以关于样式的属性要少一些。
下面介绍一些常用的一些颜色和字体相关的属性。
## 5-1 颜色相关
颜色设置主要分为单色，渐变色两种，对于 `Text`对象，`manim`还提供了更加精细的按字符设置的属性。
### 5-1-1 单色
单色设置通过 `color`属性。
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._tex()
        self.wait()
    
    def _tex(self):
        tx = Text("hello world", color=RED).shift(UP * 2.5)
        self.play(Create(tx), run_time = 1)
        tx = Text("你好，世界", color=YELLOW).shift(UP * 1.5)
        self.play(Create(tx), run_time = 1)
        tx = Text("こんにちは世界", color=GREEN).shift(UP * 0.5)
        self.play(Create(tx), run_time = 1)
        tx = Tex(r"$a^2 + b^2 = c^2$", color=RED).shift(DOWN * 0.5)
        self.play(Create(tx), run_time = 1)
        tx = Tex(r"$E = mc^2$", color=YELLOW).shift(DOWN * 1.5)
        self.play(Create(tx), run_time = 1)
        tx = Tex(r"$e^{i\pi} + 1 = 0$", color=GREEN).shift(DOWN * 2.5)
        self.play(Create(tx), run_time = 1)
```
### 5-1-2 渐变色
渐变色设置通过 `set_color_by_gradient`方法。
```Python
Text("hello world").set_color_by_gradient((RED, GREEN))
Text("你好，世界").set_color_by_gradient((YELLOW, BLUE))
Text("こんにちは世界").set_color_by_gradient((BLUE, RED))
Tex(r"$a^2 + b^2 = c^2$").set_color_by_gradient((RED, GREEN))
Tex(r"$E = mc^2$").set_color_by_gradient((YELLOW, BLUE))
Tex(r"$e^{i\pi} + 1 = 0$").set_color_by_gradient((BLUE, RED))
```
### 5-1-3 按字符设置
如果一段文本中需要突出某些字符，可以用 `t2c`属性来设置特定字符的颜色。
```Python
Text("databook.top", t2c={"data": BLUE, "book": RED, "top": GREEN})
```
对于 `Tex`对象来说，虽然没有 `t2c`属性，也可以通过 `set_color_by_tex`方法来设置特定字符的颜色。
```Python
t = Tex(r"$a^2$", " + ", r"$b^2$", " = ", r"$c^2$")
t.set_color_by_tex("a^2", RED)
t.set_color_by_tex("b^2", YELLOW)
t.set_color_by_tex("c^2", GREEN)
```
## 5-2 字体相关
`manim`可以直接使用系统中已有的字体，也可以设置字号，`Text`对象还可以设置粗体，斜体等等。
### 5-2-1 系统字体
`manim`通过 `font`属性设置字体。
```Python
Text("manim", font="Consolas")
Text("数学", font="STXingkai")  # 华文行楷
Text("之旅", font="STCaiyun")   # 华文彩云
```
### 5-2-2 字号
字号就是字体的大小，通过 `font_size`属性设置。
```Python
Text("manim", font_size=20)
Text("数", font_size=30)
Text("学", font_size=40)
Text("之", font_size=50)
Text("旅", font_size=60)
```
### 5-2-3 粗体
粗体通过 `weight`属性设置。
```Python
Text("NORMAL font weight")
Text("BOLD font weight", weight=BOLD)
```
### 5-2-4 斜体
斜体通过 `slant`属性设置。
```Python
Text("NORMAL font")
Text("ITALIC font", slant=ITALIC)
```
### 5-2-5 按字符设置
字体相关的属性也可以像颜色那样，按字符设置。相关的主要属性包括：
1. t2f：按字符设置字体
2. t2s：按字符设置斜体
3. t2w：按字符设置粗体
```Python
Text(
    "manim 数学之旅",
    t2f={"数学": "STXingkai", "之旅": "STCaiyun"},
    t2s={"ma": ITALIC},
    t2w={"nim": BOLD},
)
```
# 6 坐标系
没有引入坐标系之前，在绘制图形时，也有一个隐含的坐标系，它和屏幕的像素相关。比如，我们之前示例中的各个图形，屏幕的中心就是坐标原点（`[0, 0]`），而横纵坐标范围与设置的视频分辨率有关，分辨率设置的越高，坐标范围越大。
引入坐标系之后，绘制图形时就不用局限在屏幕隐含的坐标范围之内，通过调整坐标的刻度，我们可以基于坐标系中绘制任意范围的图形，而不用担心绘制到屏幕之外去。
`manim`已经提供了从一维到三维的坐标系对象，下面一一介绍它们的基本使用方法。
## 6-1 数轴
数轴（`NumberLine`）是最基本的一维坐标系，它的关键参数是：
1. `x_range`：设置数轴的范围和间隔
2. `length`：设置数轴显示的长度
```Python
NumberLine(x_range=[-10, 10, 2], length=10, include_numbers=True)
NumberLine(x_range=[-3, 3, 0.5], length=12, include_numbers=True)
NumberLine(
    x_range=[-5, 5 + 1, 1], # 带箭头的话需要 +1 给箭头留出位置，
    length=6, # 长度为标准长度，其他变量不变时，length 越小，数轴的刻度就越密。
    include_numbers=True,
    include_tip=True, # 带箭头
    rotation=10 * DEGREES, # 逆时针转 10 度
)
```
## 6-2 平面坐标系
平面坐标系分为两类，**实数平面**和**复数平面**，两者的外形非常类似。
### 6-2-1 实数平面
实数平面（`NumberPlane`）的关键参数有4个：
1. `x_range`：设置**X轴**的范围和间隔
2. `y_range`：设置**Y轴**的范围和间隔
3. `x_length`：设置**X轴**显示的长度
4. `y_length`：设置**Y轴**显示的长度
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._numberplane()
        self.wait()
    
    def _numberplane(self):
        np = NumberPlane(
            x_range = (-4, 11, 1), 
            y_range = (-3, 3, 1), 
            x_length = 10, 
            y_length = 6
        )
        self.play(Create(np), run_time = 1)
```
### 6-2-2 复数平面
复数平面（`ComplexPlane`）是基于实数平面（`NumberPlane`）的，参数类似， 只是多了一些标记复数的信息。
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._complexplane()
        self.wait()
    
    def _complexplane(self):
        plane = ComplexPlane(
            x_range = (-4, 11, 1), 
            y_range = (-3, 3, 1), 
            x_length = 10, 
            y_length = 6
        ).add_coordinates()
        d1 = Dot(plane.n2p(2 + 1j), color=YELLOW)
        d2 = Dot(plane.n2p(-3 - 2j), color=YELLOW)
        label1 = Tex("2+i").next_to(d1, UR, 0.1)
        label2 = Tex("-3-2i").next_to(d2, UR, 0.1)
        self.play(Create(plane), run_time = 1)
        self.play(Create(d1), run_time = 0.5)
        self.play(Create(label1), run_time = 0.5)
        self.play(Create(d2), run_time = 0.5)
        self.play(Create(label2), run_time = 0.5)
```
## 6-3 极坐标系
极坐标系（`PolarPlane`）通过角度和与原点的距离来定位位置，经常被用于导航类的系统中， 与直角坐标相比，在这类系统中能极大的简化计算。 它的关键参数有：
1. `azimuth_step`：分割的角度个数
2. `size`：极坐标在屏幕中显示的大小
3. `radius_step`：极坐标半径的间隔
4. `radius_max`：极坐标最大半径
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._polarplane()
        self.wait()
    
    def _polarplane(self):
        plane = PolarPlane(
            azimuth_step = 20,
            size = 7,
            radius_step = 1,
            radius_max = 5,
        ).add_coordinates()
        self.play(Create(plane), run_time = 3)
```
## 6-4 笛卡尔坐标系
笛卡尔坐标系是最常用的坐标系，学习函数的图像时用的最多的就是此坐标系。
### 6-4-1 二维
二维的笛卡尔坐标系（`Axes`）使用的比较多，它在平面坐标系之上，又提供了更多的配置，可以更加灵活的配置数轴。
除了上面平面坐标系提到的那4个关键参数之外，还有2个配置坐标轴的参数也很重要：
1. `x_axis_config`：配置**X轴**如何显示的参数
2. `y_axis_config`：配置**Y轴**如何显示的参数
```Python
from manim import *
import manim
class Try(Scene):
    def construct(self):
        self._axes()
        self.wait()
    
    def _axes(self):
        ax = Axes(
        x_range = [0, 10, 1],
        y_range = [-2, 6, 1],
        x_length = 6,
        tips = False,
        axis_config = {"include_numbers": True},
        y_axis_config = {"scaling": LogBase(custom_labels = True)}
        )
        graph = ax.plot(lambda x: x**2, x_range = [0.001, 10], use_smoothing = False)
        self.play(Create(ax), run_time = 1)
        self.wait()
        self.play(Create(graph), run_time = 1)
```
### 6-4-2 三维
三维的笛卡尔坐标系（`ThreeDAxes`）与二维坐标系的参数类似，只是多了一个维度（**Z轴**）的配置，其配置参数与**X轴**和**Y轴**类似。 显示三维图形时，有两点需要额外注意：
1. 场景要继承 `ThreeDScene`
2. 要调整下默认的相机位置，也就是视角的位置，默认视角是从Z轴顶部向下看的。
这个是默认相机视角：
```Python
# 这是默认相机视角，很难看出来这是三维的
from manim import *
class Try(ThreeDScene):
    def construct(self):
        axes = ThreeDAxes(y_length = 8)
        circle = Circle(color = BLUE, radius = 2)
        vg = VGroup(axes, circle)
        self.play(Create(vg), run_time = 2)
        self.wait()
```
这个是调整之后的相机视角：
```Python
from manim import *
class Try(ThreeDScene):
    def construct(self):
        axes = ThreeDAxes(y_length = 8)
        circle = Circle(color = BLUE, radius = 2)
        vg = VGroup(axes, circle)
        # 调整相机视角的代码，phi 是与 Z 轴之间的角度，theta 是围绕 Z 轴旋转的角度
        self.set_camera_orientation(phi = 75 * DEGREES, theta = 30 * DEGREES)
        self.play(Create(vg), run_time = 2)
        self.wait()
```
# 7 常用动画效果
`manim`的主要功能就是制作动画，因此它提供了各类丰富的动画效果，本篇主要介绍其中最常用的几种动画效果。
## 7-1 创建效果
展示某个元素或者文字时，一下子就全显示出来会显得比较突兀，通过创建效果的动画，让各个元素的出现更加的自然。 常用的创建效果动画主要有：`Create`，`Write`和`FadeIn`三个方法。
### 7-1-1 Create
`Create`一般用在创建图形上，绘制时图形逐步显示出来。
```Python
s = Square(side_length=2, color=BLUE)
self.play(Create(s))
```
### 7-1-2 Write
`rite`用在文字的创建上，绘制文字时逐个显示文字。
```Python
t = Text(
    "Welcome to Manim",
    t2c={"Welcome": BLUE, "Manim": RED},
    t2f={"Manim": "STCaiyun"},
)
self.play(Write(t))
```
### 7-1-3 FadeIn
`FadeIn`是一种逐渐由模糊到清晰的显示方式。
```Python
s = Square(side_length=2, color=BLUE, fill_opacity=0.6)
self.play(FadeIn(s))
```
## 7-2 销毁效果
销毁的效果一般用在移除图形和文字的场合。
### 7-2-1 Uncreate
`Uncreate`一般用在擦除图形。
```Python
s = Square(side_length=2, color=BLUE)
self.add(s)
self.wait(0.5)
self.play(Uncreate(s))
```
### 7-2-2 Unwrite
`Unwrite`一般用在擦除文字。
```Python
t = Text(
    "Welcome to Manim",
    t2c={"Welcome": BLUE, "Manim": RED},
    t2f={"Manim": "STCaiyun"},
)
self.add(t)
self.wait(0.5)
self.play(Unwrite(t))
```
### 7-2-3 FadeOut
`FadeOut`是一种逐渐消失的显示方式。
```Python
s = Square(side_length=2, color=BLUE, fill_opacity=0.6)
self.add(s)
self.wait(0.5)
self.play(FadeOut(s))
```
## 7-3 移动效果
移动的动画有两个函数：
1. `shift`：移动指定的距离
2. `move_to`：移动到指定点
```Python
s = Square(side_length=1, color=BLUE, fill_opacity=0.6)
self.add(s)
self.play(s.animate.shift(RIGHT))  # 右移1个单位
self.play(s.animate.shift(UP))  # 上移1个单位
self.play(s.animate.shift(LEFT * 2))  # 左移2个单位
self.play(s.animate.shift(DOWN * 3))  # 下移3个单位
self.play(s.animate.move_to(ORIGIN))  # 移动到中心处
```
## 7-4 旋转效果
旋转 `Rotate`，通过设置角度和旋转的中心来控制旋转效果。
原地自旋：
```Python
s = Square(side_length=2, color=BLUE, fill_opacity=0.6)
self.add(s)
self.play(Rotate(s, angle=2 * PI), run_time=2)  # 自旋转1周
self.wait(0.5)
```
绕某个中心点旋转：
```Python
s = Square(side_length=1, color=BLUE, fill_opacity=0.6).shift(UP)
self.add(s)
# 绕屏幕中心旋转1周
self.play(Rotate(s, angle=2 * PI, about_point=ORIGIN), run_time=2)
self.wait(0.5)
```
## 7-5 变换效果
变换也是使用的比较多的一种动画效果。
尤其是在数学视频中，经常遇到随着参数的变化，图形随之变形；或者反之。
### 7-5-1 图形变换
变换时既可以保留原图形（`TransformFromCopy`），也可以从原图形直接变换成新的图形（`ReplacementTransform`）
保留原图形：
```Python
s = Square(side_length=1, color=BLUE, fill_opacity=0.6).shift(LEFT * 2)
c = Circle(radius=1, color=RED, fill_opacity=0.6).shift(RIGHT * 2)
self.add(s)
self.wait(0.5)
self.play(TransformFromCopy(s, c))
```
不保留原图形：
```Python
s = Square(side_length=1, color=BLUE, fill_opacity=0.6).shift(LEFT * 2)
c = Circle(radius=1, color=RED, fill_opacity=0.6).shift(RIGHT * 2)
self.add(s)
self.wait(0.5)
self.play(ReplacementTransform(s, c))
```
### 7-5-2 文字变换
文字变换与图形变换类似。
保留原文字：
```Python
t1 = Tex(r"$(a+b)^2$").shift(UP)
t2 = Tex(r"$a^2 + 2ab + b^2$")
self.add(t1)
self.wait(0.5)
self.play(TransformFromCopy(t1, t2))
```
不保留原文字：
```Python
t1 = Tex(r"$(a+b)^2$").shift(UP)
t2 = Tex(r"$a^2 + 2ab + b^2$")
self.add(t1)
self.wait(0.5)
self.play(ReplacementTransform(t1, t2))
```
# 8 高级动画效果
在常用的动画效果中，介绍了一些元素的创建，销毁，移动和变换的方法，这些方法都是针对单个动画的。如果需要多个动画互相关联，或者元素需要有更复杂的运动方式，那么，仅仅依靠常用的动画效果可能就无法满足要求了。
本篇的高级动画效果主要介绍一些更加灵活的元素运动方式，如何组合多个动画，以及如何联动多个动画的方式。掌握了这些方法，就能够表达出更加复杂的数学几何动画。
## 8-1 沿着路径运动
常用的动画一般都是直线运动或者圆弧运动，而 `MoveAlongPath` 可以让元素沿着任意的函数轨迹来运动。 下面的示例是一个点沿着一个较为复杂的三角函数形成的路径运动。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        cos_func = FunctionGraph(
        lambda t: np.cos(t) + 0.5 * np.cos(7 * t) + (1 / 7) * np.cos(14 * t),
        color=RED,
        )
        self.add(cos_func)
        d1 = Dot(cos_func.get_start())
        self.play(MoveAlongPath(d1, cos_func), rate_func=linear, run_time=10)
        self.wait()
```
## 8-2 保留运动路径
保留动画的轨迹，可以更好的追踪元素的变化规律。 通过 `TracedPath`可以设置保留运动轨迹的效果。 下面的示例是一个点以一定的弧度运行，并将其运行的轨迹绘制出来。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        d = Dot(RIGHT * 2)
        b = TracedPath(d.get_center)
        self.add(d, b)
        self.play(d.animate(path_arc=PI / 4).shift(LEFT * 2))
        self.play(d.animate(path_arc=-PI / 4).shift(LEFT * 2))
        self.wait()
```
## 8-3 动画组合
在常用的动画效果中，一般都是逐个显示各个动画效果，`manim`中提供了几个控制动画组合的方式。 用的较多的两个分别是：
1. 多个动画组合时，设置每个动画的延迟启动时间
2. 多个动画组合时，前一个动画成功执行后再执行下一个动画
### 8-3-1 延迟启动
通过 `LaggedStart`控制组合的多个动画之间的启动时间间隔。 下面的示例是一个点先启动，但是要运行**1秒**才到达终点；另一个点延迟**0.5秒**启动，但是运行**0.5秒**就到达终点，所以两个点最终应该**同时到达**。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        d1 = Dot(LEFT * 2 + UP, color=RED)
        d2 = Dot(LEFT * 2 + DOWN)
        dl = DashedLine(
            RIGHT * 2 + UP * 3,
            RIGHT * 2 + DOWN * 3,
            dash_length=0.1,
            dashed_ratio=0.8,
            stroke_width=2,
            color=GREEN,
        )
        self.add(d1, d2, dl)
        self.wait(0.5)

        ani1 = d1.animate(run_time=1).shift(RIGHT * 4)
        ani2 = d2.animate(run_time=0.5).shift(RIGHT * 4)

        self.play(LaggedStart(ani1, ani2, lag_ratio=0.5))
        
        self.wait()
```
### 8-3-2 顺序启动
通过 `Succession`控制多个动画顺序执行，它能够保证上一个执行成功后才执行下一个。 下面的示例是4个不同颜色的点，每个点移动成功之后，移动下一个点。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        dot1 = Dot(point=LEFT * 2 + UP * 2, radius=0.16, color=BLUE)
        dot2 = Dot(point=LEFT * 2 + DOWN * 2, radius=0.16, color=MAROON)
        dot3 = Dot(point=RIGHT * 2 + DOWN * 2, radius=0.16, color=GREEN)
        dot4 = Dot(point=RIGHT * 2 + UP * 2, radius=0.16, color=YELLOW)
        self.add(dot1, dot2, dot3, dot4)

        self.play(
            Succession(
                dot1.animate.move_to(dot2),
                dot2.animate.move_to(dot3),
                dot3.animate.move_to(dot4),
                dot4.animate.move_to(dot1),
            )
        )
        self.wait()
```
## 8-4 动画联动
动画联动是比动画组合更复杂的一种模式，动画组合时，每个动画其实是固定的，只是启动的时机不一样。
而在动画联动中，一个动画如何运行是完全基于另一个动画的，而不是实现预设的。
下面的示例是一个角度的联动效果，
初始元素有：
1. 两条线`line1`和 `line_moving`组成的角度
2. 标识角度的一段弧线`a`
3. 标识角度的字母 `tex`
4. 显示角度数值的文字 `theta_tex`。
初始角度 `110°`，然后可以看到随着 `line_moving`的移动（先变成 `90°`，再增加 `140°`）， `a`，`tex`和`theta_tex`的联动效果。
```Python
from manim import *
class Try(Scene):
    def construct(self):
        rotation_center = LEFT
        theta_tracker = ValueTracker(110)
        line1 = Line(LEFT, RIGHT)
        line_moving = Line(LEFT, RIGHT)
        line_ref = line_moving.copy()
        line_moving.rotate(theta_tracker.get_value() * DEGREES, about_point=rotation_center)
        a = Angle(line1, line_moving, radius=0.5, other_angle=False)
        tex = MathTex(r"\theta").move_to(
            Angle(
                line1, line_moving, radius=0.5 + 3 * SMALL_BUFF, other_angle=False
            ).point_from_proportion(0.5)
        )

        theta_tex = Tex(
            r"$\theta = $",
            str(int(theta_tracker.get_value())),
            r"$^\circ$",
            font_size=50,
            color=RED,
        ).shift(UP * 2)

        self.add(line1, line_moving, a, tex, theta_tex)
        self.wait()

        line_moving.add_updater(
            lambda x: x.become(line_ref.copy()).rotate(
                theta_tracker.get_value() * DEGREES, about_point=rotation_center
            )
        )
        a.add_updater(
            lambda x: x.become(Angle(line1, line_moving, radius=0.5, other_angle=False))
        )
        tex.add_updater(
            lambda x: x.move_to(
                Angle(
                    line1, line_moving, radius=0.5 + 3 * SMALL_BUFF, other_angle=False
                ).point_from_proportion(0.5)
            )
        )
        theta_tex.add_updater(
            lambda x: x.become(
                Tex(
                    r"$\theta = $",
                    str(int(theta_tracker.get_value())),
                    r"$^\circ$",
                    font_size=50,
                    color=RED,
                ).shift(UP * 2)
            )
        )

        self.play(theta_tracker.animate.set_value(90))
        self.play(theta_tracker.animate.increment_value(140), run_time=3)

        self.wait()
```
**未完待续** 