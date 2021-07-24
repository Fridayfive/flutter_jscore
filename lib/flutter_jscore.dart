
import 'dart:async';
import 'dart:ffi';
import 'dart:io';

import 'package:flutter/services.dart';

class FlutterJscore {
  static const MethodChannel _channel =
      const MethodChannel('flutter_jscore');

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
final DynamicLibrary JSBridge = Platform.isAndroid
    ? DynamicLibrary.open("libafc.so")
    : DynamicLibrary.process();

final void Function() init =
JSBridge.lookup<NativeFunction<Void Function()>>("initJSC").asFunction();
