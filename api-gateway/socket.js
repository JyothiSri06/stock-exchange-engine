let io;

exports.setIO = (socketIO) => {
  io = socketIO;
};

exports.getIO = () => {
  return io;
};