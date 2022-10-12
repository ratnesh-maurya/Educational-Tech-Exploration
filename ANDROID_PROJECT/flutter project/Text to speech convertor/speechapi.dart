import 'package:flutter/material.dart';
import 'package:speech_to_text/speech_to_text.dart';

class Speechapi{
static final _speech=SpeechToText();

static Future<bool>togglerecording({required Function(String text) onresult,
required ValueChanged<bool>onlistening})async{
  if(_speech.isListening){
    _speech.stop();return true;
  }
  final isAvailable=await _speech.initialize(onStatus: (status)=>onlistening(_speech.isListening),
  onError: (e)=>print('Error: $e'));
  if(isAvailable){
    _speech.listen(onResult: (value)=>onresult(value.recognizedWords));
  }
  return isAvailable;
}
}