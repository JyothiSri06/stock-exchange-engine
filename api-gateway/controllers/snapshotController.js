const snapshotService =
    require("../services/snapshotService");

exports.getSnapshot = (req, res) => {

    const snapshot =
        snapshotService.getSnapshot();

    res.json(snapshot);
};