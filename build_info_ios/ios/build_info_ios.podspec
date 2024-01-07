#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint build_info_ios.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'build_info_ios'
  s.version          = '0.0.1'
  s.summary          = 'Flutter plugin for BuildInfo.'
  s.description      = <<-DESC
A Flutter Plugin for making the underlying platform BuildInfo.
                       DESC
  s.homepage         = 'https://github.com/craftsoft-dev/flutter_build_info'
  s.license          = { :type => 'BSD', :file => '../LICENSE' }
  s.author           = { 'Craftsoft LLC' => 'inquiry@craftsoft.jp' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*.swift'
  s.dependency 'Flutter'
  s.platform = :ios, '11.0'

  # Flutter.framework does not contain a i386 slice.
  s.pod_target_xcconfig = { 'DEFINES_MODULE' => 'YES', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386' }
  s.swift_version = '5.0'
end
