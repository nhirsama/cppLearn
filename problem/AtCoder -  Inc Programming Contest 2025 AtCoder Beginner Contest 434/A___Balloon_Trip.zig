const std = @import("std");

pub fn main() !void {
    var in_buf: [1024]u8 = undefined;
    var cin = std.fs.File.stdin().reader(&in_buf);

    const line = try cin.interface.takeDelimiterExclusive('\n');
    var it = std.mem.tokenizeAny(u8, line, " \t");

    const w = try std.fmt.parseInt(i32, it.next().?, 10);
    const b = try std.fmt.parseInt(i32, it.next().?, 10);

    var out_buf: [64]u8 = undefined;
    var writer = std.fs.File.stdout().writer(&out_buf);
    try writer.interface.print("{}", .{@divFloor(w * 1000, b) + 1});
    try writer.interface.flush();
}
