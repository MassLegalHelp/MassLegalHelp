use Digest::MD5 qw(md5 md5_hex md5_base64);
print $digest = md5('LyaD7dgtS8yKu-kcUVeDcg'); print "\n";
print $digest = md5_hex('LyaD7dgtS8yKu-kcUVeDcg'); print "\n";
print $digest = md5_base64('LyaD7dgtS8yKu-kcUVeDcg'); print "\n";
 #print 
 # OO style
 use Digest::MD5;
 $ctx = Digest::MD5->new;
 $ctx->add("tSpNkUhBG0SFnk3KtFXfpw");
 #$ctx->addfile($file_handle);
 $digest = $ctx->digest;
 $digest = $ctx->hexdigest;
 $digest = $ctx->b64digest;