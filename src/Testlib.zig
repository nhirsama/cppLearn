const std = @import("std");
pub fn main() !void {
    var n:i2 = 0;
    n = n-1;
    std.debug.print("Hello World!{}", .{n});
}