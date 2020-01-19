//
//  ContentView.swift
//  DesignCode
//
//  Created by 杨磊 on 2019/10/28.
//  Copyright © 2019 Yang To. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        ZStack {
            tetleView()
            //                .blur(radius: 20)
            cardBottomView()
            //                .blur(radius: 20)
            CardView()
                .offset(y: -40)
                .scaleEffect(0.85)
                .rotationEffect(Angle(degrees: 20))
                .rotation3DEffect(Angle(degrees: 50), axis: /*@START_MENU_TOKEN@*/(x: 10.0, y: 10.0, z: 10.0)/*@END_MENU_TOKEN@*/)
                .blendMode(.hardLight)

            CardView()
                .offset(y: -20)
                .scaleEffect(0.90)
                .rotationEffect(Angle(degrees: 15))
                .rotation3DEffect(Angle(degrees: 40), axis: /*@START_MENU_TOKEN@*/(x: 10.0, y: 10.0, z: 10.0)/*@END_MENU_TOKEN@*/)
                .blendMode(.hardLight)
            CertificateView()
                .scaleEffect(0.95)
                .rotationEffect(Angle(degrees: 5))
                .rotation3DEffect(Angle(degrees: 30), axis: /*@START_MENU_TOKEN@*/(x: 10.0, y: 10.0, z: 10.0)/*@END_MENU_TOKEN@*/)

        }

    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

struct CardView: View {
    var body: some View {
        VStack {
            Text("Card Back")
        }
            .frame(width: 340, height: 220) //定义大小 放在第一位
            .background(Color.blue) //背景 其次
            .cornerRadius(10)
            .shadow(radius: 20)
    }
}

struct CertificateView: View {
    var body: some View {
        VStack{  //最外围的容器 垂直
            HStack{     //Hstack 用于水平
                VStack(alignment:.leading){ //VStack 用于垂直
                    Text("UI 设计")
                        .font(.headline)  //字体类型
                        .fontWeight(.bold)  //字体粗细
                        .foregroundColor(Color("accent")) //字体颜色
                        .padding(.top)

                    Text("证书")
                        .foregroundColor(Color.white) //字体颜色
                        .padding(.top)

                }
                Spacer()  //空间 用于占位置
                Image("Logo")
                    .resizable() //定义大小 必须
                    .frame(width: 30.0, height: 30.0)  //定义图片的高和宽
            }
                .padding(.horizontal)  // 水平填充 hrizontal=leading+trailling
            Spacer()
            Image("Certificate1")
        }
        .frame(width: 340.0, height: 220.0)
            .background(Color.black)  //背景色
            .cornerRadius(10)       //圆角
            .shadow(radius: 20)
    }
}

struct tetleView: View {
    var body: some View {
        VStack {
            HStack {
                Text("证书")
                    .font(.largeTitle)
                    .fontWeight(.bold)
                Spacer()
            }
            Image("Illustration5")
            Spacer()
        }
        .padding()
    }
}

struct cardBottomView: View {
    var body: some View {
        VStack(spacing: 20.0) {
            Rectangle()
                .frame(width:60,height: 6)
                .cornerRadius(3)
                .opacity(0.1)  //不透明
            Text("这是一行测试文字 这是一行测试文字 这是一行测试文字 这是一行测试文字 这是一行测试文字 这是一行测试文字 这是一行测试文字 ")
            Spacer()
        }
            .frame(minWidth:0,maxHeight: .infinity) //使用其他容器来撑开空间  infinity 最大
            .padding()
            .padding(.horizontal)
            .background(Color.white)
            .cornerRadius(30)
            .shadow(radius: 20) // 需要背景颜色
            .offset(x:0,y:620)
    }
}
