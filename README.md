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
