import 'package:avatar_glow/avatar_glow.dart';
import 'package:clipboard/clipboard.dart';
import 'package:flutter/material.dart';
import 'package:speechtext/speechapi.dart';
import 'package:speechtext/utils.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // Try running your application with "flutter run". You'll see the
        // application has a blue toolbar. Then, without quitting the app, try
        // changing the primarySwatch below to Colors.green and then invoke
        // "hot reload" (press "r" in the console where you ran "flutter run",
        // or simply save your changes to "hot reload" in a Flutter IDE).
        // Notice that the counter didn't reset back to zero; the application
        // is not restarted.
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
 String text="Press mic to start";
bool islistening=false;
  @override
  Widget build(BuildContext context) {
    return Scaffold(

      appBar: AppBar(
actions: [Builder(builder: (context)=>IconButton(onPressed: ()async{
  await FlutterClipboard.copy(text);
 final snackBar= SnackBar(content: Text("Copy to clipboard"));
  ScaffoldMessenger.of(context).showSnackBar(snackBar);
}, icon: Icon(Icons.copy)))
  ],
      ),floatingActionButtonLocation: FloatingActionButtonLocation.centerFloat,
      floatingActionButton:AvatarGlow(child: FloatingActionButton(
        onPressed:   (){
        togglerecording();
      },child: Icon(islistening?Icons.mic:Icons.mic_none,size: 50,),),
          animate: islistening, endRadius: 150,glowColor: Colors.green,showTwoGlows: true),

      body: SingleChildScrollView(reverse: true,
          child:Text("$text")),


    );
  }
  Future togglerecording()=>Speechapi.togglerecording(onresult:  (text)=>setState(()=>this.text=text,),
  onlistening: (islistening){
    setState(()=>this.islistening=islistening);
 if(!islistening){
   Future.delayed(Duration(seconds: 3),(){
     Utils.scanText(text);
   });

 }
 }
  );

}
