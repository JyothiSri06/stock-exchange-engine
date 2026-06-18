const express = require("express");

const router = express.Router();

const snapshotController =
    require("../controllers/snapshotController");

router.get(
    "/",
    snapshotController.getSnapshot
);

module.exports = router;