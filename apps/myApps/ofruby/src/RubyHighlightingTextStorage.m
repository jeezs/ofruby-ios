#import "RubyHighlightingTextStorage.h"

@implementation RubyHighlightingTextStorage
{
	NSMutableAttributedString* mStr;
}

- (id)init
{
	self = [super init];
	
	if (self) {
		mStr = [NSMutableAttributedString new];
	}
	
	return self;
}

- (NSString *)string
{
	return mStr.string;
}

- (NSDictionary *)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRangePointer)range
{
	return [mStr attributesAtIndex:location effectiveRange:range];
}

- (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)str
{
	[mStr replaceCharactersInRange:range withString:str];
	[self edited:NSTextStorageEditedCharacters range:range changeInLength:(NSInteger)str.length - (NSInteger)range.length];
}

- (void)setAttributes:(NSDictionary *)attrs range:(NSRange)range
{
	[mStr setAttributes:attrs range:range];
	[self edited:NSTextStorageEditedAttributes range:range changeInLength:0];
}

- (void)processEditing
{
    NSArray* syntaxArray = [[NSArray alloc] initWithObjects:
        //                                pattern,            color
        [[NSArray alloc] initWithObjects: @"#[^\r\n]*[\r\n]", [UIColor colorWithRed:0.00 green:0.50 blue:0.00 alpha:1.0], nil],
        [[NSArray alloc] initWithObjects: @"(?<!\\w)(BEGIN|END|__ENCODING__|__END__|__FILE__|__LINE__|alias|and|begin|break|case|class|def|defined\\?|do|else|elsif|end|ensure|false|for|if|in|module|next|nil|not|or|redo|rescue|retry|return|self|super|then|true|undef|unless|until|when|while|yield)(?!\\w)", [UIColor colorWithRed:0.08 green:0.09 blue:1.00 alpha:1.0], nil],
        nil
        ];

    NSRange paragaphRange = [self.string paragraphRangeForRange: self.editedRange];
    [self removeAttribute:NSForegroundColorAttributeName range:paragaphRange];
	
    for (NSArray* highlightRule in syntaxArray) {
        NSRegularExpression* regex = [NSRegularExpression regularExpressionWithPattern:highlightRule[0]
                                                                               options:NSRegularExpressionDotMatchesLineSeparators
                                                                                 error:nil];
	
        [regex enumerateMatchesInString:self.string options:0 range:paragaphRange usingBlock:^(NSTextCheckingResult *result, NSMatchingFlags flags, BOOL *stop) {
                [self addAttribute:NSForegroundColorAttributeName
                             value:highlightRule[1]
                             range:result.range];
            }];
    }
  
    [super processEditing];
}

@end