# UE4_EditorExtension
这个工程包含了如下功能：
### Easy-To-Use MenuExtension 菜单栏轻松扩展
You only need to Inheritance “**UMenuItem**“ ,then registered path on "**Init**" function,write your own code on "**OnMenuClick**" funtion.You'll see your menu in the unreal menu bar.  

只需要继承**UMenuItem**，并且在构造函数里调用**Init**函数，传入菜单栏路径和提示。接着在**OnMenuClick**写你想要的任何逻辑。就能在菜单栏看到你的菜单。使用案例**UTestLogMenu**。
![在这里插入图片描述](https://img-blog.csdnimg.cn/1eadf85cf9a54e0689dee4484fc1cf41.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/bec26196b6d7423f9440168862a99ab4.png?x-oss-process=image/watermark,type_d3F5LXplbmhlaQ,shadow_50,text_Q1NETiBA5rC05puc5pel6bih,size_20,color_FFFFFF,t_70,g_se,x_16#pic_center)
![在这里插入图片描述](https://img-blog.csdnimg.cn/f887c22fa1e14f5f878b18c705a334d9.png#pic_center)

实现原理讲解：
[【UE·Editor篇】做一个超好用的菜单栏扩展框架](https://zhuanlan.zhihu.com/p/441017278)
***
### 学习资料
- [一文搞懂StaticClass、GetClass和ClassDefaultObject](https://zhuanlan.zhihu.com/p/380809095)
- [编辑器扩展：自定义菜单栏](http://supervj.top/2021/08/09/%E7%BC%96%E8%BE%91%E5%99%A8%E6%89%A9%E5%B1%95%EF%BC%9A%E8%87%AA%E5%AE%9A%E4%B9%89%E8%8F%9C%E5%8D%95%E6%A0%8F/)
- [Creating an Editor Module](https://michaeljcole.github.io/wiki.unrealengine.com/Creating_an_Editor_Module/)
- [UE4 插件扩展引擎工具栏](https://www.cnblogs.com/jqm304775992/p/8996470.html)
- [UE4 编辑器扩展 优雅地扩展菜单栏](https://zhuanlan.zhihu.com/p/432072854)
- [UE4.26 几种编辑器扩展方法](https://zhuanlan.zhihu.com/p/380399264)
- [高级编辑器扩展合集（自定义布局、自定义Filter、自定义预览窗口等）](https://blog.csdn.net/u013412391/category_10839272.html)
