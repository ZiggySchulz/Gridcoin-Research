

#include <QtGlobal>

// Automatically generated by extract_strings_qt.py
#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif
static const char UNUSED *bitcoin_strings[] = {
QT_TRANSLATE_NOOP("bitcoin-core", "None"),
QT_TRANSLATE_NOOP("bitcoin-core", "The %s developers"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"%s, you must set a rpcpassword in the configuration file:\n"
" %s\n"
"It is recommended you use the following random password:\n"
"rpcuser=gridcoinrpc\n"
"rpcpassword=%s\n"
"(you do not need to remember this password)\n"
"The username and password MUST NOT be the same.\n"
"If the file does not exist, create it with owner-readable-only file "
"permissions.\n"
"It is also recommended to set alertnotify so you are notified of problems;\n"
"for example: alertnotify=echo %%s | mail -s \"Gridcoin Alert\" admin@foo."
"com\n"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"A poll with a yes/no/abstain response type cannot include any additional "
"custom choices."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"An error occurred while setting up the RPC port %u for listening on IPv4: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"An error occurred while setting up the RPC port %u for listening on IPv6, "
"falling back to IPv4: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Cannot obtain a lock on data directory %s. %s is probably already running "
"and using that directory."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Cannot obtain a lock on data directory %s. %s is probably already running."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Due to the failure to delete the blockchain data you will be required to "
"manually delete the data before starting your wallet."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error initializing database environment %s! To recover, BACKUP THAT "
"DIRECTORY, then remove everything from it except for wallet.dat."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: The transaction was rejected.  This might happen if some of the coins "
"in your wallet were already spent, such as if you used a copy of wallet.dat "
"and coins were spent in the copy but not marked as spent here."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: The transaction was rejected. This might happen if some of the coins "
"in your wallet were already spent, such as if you used a copy of wallet.dat "
"and coins were spent in the copy but not marked as spent here."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: This transaction requires a transaction fee of at least %s because of "
"its amount, complexity, or use of recently received funds  "),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: This transaction requires a transaction fee of at least %s because of "
"its amount, complexity, or use of recently received funds "),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Error: Unsupported argument -socks found. Setting SOCKS version isn't "
"possible anymore, only SOCKS5 proxies are supported."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Failed to download snapshot as mandatory client is available for download."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Failure to do so will result in undefined behaviour or failure to start "
"wallet."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"The wallet will now shutdown. Please start your wallet to begin sync from "
"zero"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Unable to bind to %s on this computer. Gridcoin is probably already running."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Unable to download a snapshot, as the wallet has detected that a new "
"mandatory version is available for install. The mandatory upgrade must be "
"installed before the snapshot can be downloaded and applied."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"WARNING: A mandatory release is available. Please upgrade as soon as "
"possible."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"WARNING: Blockchain data may be corrupted.\n"
"\n"
"Gridcoin detected bad index entries. This may occur because of an unexpected "
"exit, a power failure, or a late software upgrade.\n"
"\n"
"Please exit Gridcoin, open the data directory, and delete:\n"
" - the blk****.dat files\n"
" - the txleveldb folder\n"
"\n"
"Your wallet will re-download the blockchain. Your balance may appear "
"incorrect until the synchronization finishes.\n"),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: -paytxfee is set very high! This is the transaction fee you will "
"pay if you send a transaction."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: Ending this process after Stage 2 will result in syncing from 0 or "
"an incomplete/corrupted blockchain."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: Please check that your computer's date and time are correct! If "
"your clock is wrong Gridcoin will not work properly."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: error reading wallet.dat! All keys read correctly, but transaction "
"data or address book entries might be missing or incorrect."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"Warning: wallet.dat corrupt, data salvaged! Original wallet.dat saved as "
"wallet.{timestamp}.bak in %s; if your balance or transactions are incorrect "
"you should restore from a backup."),
QT_TRANSLATE_NOOP("bitcoin-core", ""
"You must set rpcpassword=<password> in the configuration file:\n"
"%s\n"
"If the file does not exist, create it with owner-readable-only file "
"permissions."),
QT_TRANSLATE_NOOP("bitcoin-core", "A poll choice cannot be empty."),
QT_TRANSLATE_NOOP("bitcoin-core", "Are you sure you want to cancel the snapshot operation?"),
QT_TRANSLATE_NOOP("bitcoin-core", "Balance too low to create a contract."),
QT_TRANSLATE_NOOP("bitcoin-core", "Balance"),
QT_TRANSLATE_NOOP("bitcoin-core", "Block Version"),
QT_TRANSLATE_NOOP("bitcoin-core", "Block file load progress "),
QT_TRANSLATE_NOOP("bitcoin-core", "Block not in index"),
QT_TRANSLATE_NOOP("bitcoin-core", "Block read failed"),
QT_TRANSLATE_NOOP("bitcoin-core", "Blocks Loaded"),
QT_TRANSLATE_NOOP("bitcoin-core", "Blocks Verified"),
QT_TRANSLATE_NOOP("bitcoin-core", "Boinc Reward"),
QT_TRANSLATE_NOOP("bitcoin-core", "CPID Count"),
QT_TRANSLATE_NOOP("bitcoin-core", "CPID count polls are not supported."),
QT_TRANSLATE_NOOP("bitcoin-core", "CPID"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cancel snapshot operation?"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cancel"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot downgrade wallet"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot resolve -bind address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot resolve -externalip address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot write default address"),
QT_TRANSLATE_NOOP("bitcoin-core", "Cannot write to data directory '%s'; check permissions."),
QT_TRANSLATE_NOOP("bitcoin-core", "Click \"Show Details\" to view changes in latest update."),
QT_TRANSLATE_NOOP("bitcoin-core", "Client Version"),
QT_TRANSLATE_NOOP("bitcoin-core", "Could not create transaction. See debug.log."),
QT_TRANSLATE_NOOP("bitcoin-core", "Datadir: "),
QT_TRANSLATE_NOOP("bitcoin-core", "Difficulty"),
QT_TRANSLATE_NOOP("bitcoin-core", "Directories:"),
QT_TRANSLATE_NOOP("bitcoin-core", "Disabled by configuration"),
QT_TRANSLATE_NOOP("bitcoin-core", "Done loading"),
QT_TRANSLATE_NOOP("bitcoin-core", "Duplicate poll choice: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", "Duplicate response for poll choice: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", "ERROR"),
QT_TRANSLATE_NOOP("bitcoin-core", "Eligible for Research Rewards"),
QT_TRANSLATE_NOOP("bitcoin-core", "Entire balance reserved"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading %s: Wallet corrupted"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading blkindex.dat"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat: Wallet corrupted"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error loading wallet.dat: Wallet requires newer version of Gridcoin"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error"),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Transaction creation failed  "),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Transaction creation failed."),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Wallet locked, unable to create transaction  "),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Wallet locked, unable to create transaction."),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: Wallet unlocked for staking only, unable to create transaction."),
QT_TRANSLATE_NOOP("bitcoin-core", "Error: could not start node"),
QT_TRANSLATE_NOOP("bitcoin-core", "Exceeded the number of choices in the poll: %s"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to download snapshot.zip; See debug.log"),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to listen on any port. Use -listen=0 if you want this."),
QT_TRANSLATE_NOOP("bitcoin-core", "Failed to rename bootstrap file to .old for backup purposes."),
QT_TRANSLATE_NOOP("bitcoin-core", "Fees Collected"),
QT_TRANSLATE_NOOP("bitcoin-core", "Files:"),
QT_TRANSLATE_NOOP("bitcoin-core", "GB)"),
QT_TRANSLATE_NOOP("bitcoin-core", "GB/"),
QT_TRANSLATE_NOOP("bitcoin-core", "Get help for a command"),
QT_TRANSLATE_NOOP("bitcoin-core", "GitHub version: "),
QT_TRANSLATE_NOOP("bitcoin-core", "Gridcoin Update Available"),
QT_TRANSLATE_NOOP("bitcoin-core", "Gridcoin version"),
QT_TRANSLATE_NOOP("bitcoin-core", "Gridcoin"),
QT_TRANSLATE_NOOP("bitcoin-core", "Height"),
QT_TRANSLATE_NOOP("bitcoin-core", "Importing blockchain data file(s)."),
QT_TRANSLATE_NOOP("bitcoin-core", "Importing bootstrap blockchain data file."),
QT_TRANSLATE_NOOP("bitcoin-core", "Initialization sanity check failed. Gridcoin is shutting down."),
QT_TRANSLATE_NOOP("bitcoin-core", "Initializing beacon registry from stored history..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Initializing local researcher context..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Initializing research reward accounting..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Insufficient funds"),
QT_TRANSLATE_NOOP("bitcoin-core", "Insufficient funds."),
QT_TRANSLATE_NOOP("bitcoin-core", "Interest"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -proxy address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid -tor address: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -mininput=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -paytxfee=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -peertimeout=<amount>: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount for -reservebalance=<amount>"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid amount"),
QT_TRANSLATE_NOOP("bitcoin-core", "Invalid team"),
QT_TRANSLATE_NOOP("bitcoin-core", "Is Superblock"),
QT_TRANSLATE_NOOP("bitcoin-core", "KB/s"),
QT_TRANSLATE_NOOP("bitcoin-core", "Latest Version GitHub data response:"),
QT_TRANSLATE_NOOP("bitcoin-core", "List commands"),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading Network Averages..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading addresses..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading banlist..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading beacon history..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading block index..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading superblock cache..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Loading wallet..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Local version: "),
QT_TRANSLATE_NOOP("bitcoin-core", "MB/s"),
QT_TRANSLATE_NOOP("bitcoin-core", "Magnitude"),
QT_TRANSLATE_NOOP("bitcoin-core", "Magnitude+Balance"),
QT_TRANSLATE_NOOP("bitcoin-core", "Magnitude-only polls are not supported."),
QT_TRANSLATE_NOOP("bitcoin-core", "Malformed CPID"),
QT_TRANSLATE_NOOP("bitcoin-core", "Multiple Choice"),
QT_TRANSLATE_NOOP("bitcoin-core", "N/A"),
QT_TRANSLATE_NOOP("bitcoin-core", "No UTXOs available due to reserve balance"),
QT_TRANSLATE_NOOP("bitcoin-core", "No address contains %s GRC in %s UTXOs or fewer."),
QT_TRANSLATE_NOOP("bitcoin-core", "No coins"),
QT_TRANSLATE_NOOP("bitcoin-core", "No current polls"),
QT_TRANSLATE_NOOP("bitcoin-core", "No eligible outputs greater than 1 GRC."),
QT_TRANSLATE_NOOP("bitcoin-core", "No mature coins"),
QT_TRANSLATE_NOOP("bitcoin-core", "No wallet available."),
QT_TRANSLATE_NOOP("bitcoin-core", "Offline"),
QT_TRANSLATE_NOOP("bitcoin-core", "Organization"),
QT_TRANSLATE_NOOP("bitcoin-core", "Participant Count"),
QT_TRANSLATE_NOOP("bitcoin-core", "Participant count polls are not supported."),
QT_TRANSLATE_NOOP("bitcoin-core", "Please enter a poll discussion website URL."),
QT_TRANSLATE_NOOP("bitcoin-core", "Please enter a poll title."),
QT_TRANSLATE_NOOP("bitcoin-core", "Please enter at least one response."),
QT_TRANSLATE_NOOP("bitcoin-core", "Please enter at least two poll choices."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll cannot contain more than %s choices."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll choice \"%s\" exceeds %s characters."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll discussion URL cannot exceed %s characters."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll duration cannot exceed %s days."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll duration must be at least %s days."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll has already finished."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll only allows a single choice."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll question cannot exceed %s characters."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll signature failed. See debug.log."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll title cannot exceed %s characters."),
QT_TRANSLATE_NOOP("bitcoin-core", "Poll with that title already exists. Please choose another title."),
QT_TRANSLATE_NOOP("bitcoin-core", "Pool"),
QT_TRANSLATE_NOOP("bitcoin-core", "Project email mismatch"),
QT_TRANSLATE_NOOP("bitcoin-core", "Quorum Hash"),
QT_TRANSLATE_NOOP("bitcoin-core", "Reindexing blockchain from on disk block data files..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Replaying contracts..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Rescanning..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Reset Blockchain Data: Blockchain data removal failed."),
QT_TRANSLATE_NOOP("bitcoin-core", "Reset Blockchain Data: Blockchain data removal was a success"),
QT_TRANSLATE_NOOP("bitcoin-core", "Resetting block chain index to prepare for reindexing..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Send command to -server or gridcoinresearchd"),
QT_TRANSLATE_NOOP("bitcoin-core", "Sending..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Single Choice"),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot Process Complete!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot Process Has Begun."),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot extraction failed! Cleaning up any extracted data"),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot operation canceled due to an invalid snapshot zip."),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot operation canceled."),
QT_TRANSLATE_NOOP("bitcoin-core", "Snapshot operation successful!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (1/4): Downloading snapshot.zip:         "),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (1/4): Downloading snapshot.zip: Speed "),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (2/4): Verify SHA256SUM of snapshot.zip"),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (2/4): Verify SHA256SUM of snapshot.zip: "),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (3/4): Cleanup blockchain data"),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (3/4): Cleanup blockchain data:          "),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (4/4): Extracting snapshot.zip"),
QT_TRANSLATE_NOOP("bitcoin-core", "Stage (4/4): Extracting snapshot.zip:          "),
QT_TRANSLATE_NOOP("bitcoin-core", "Staking Only - Investor Mode"),
QT_TRANSLATE_NOOP("bitcoin-core", "Staking Only - No Eligible Research Projects"),
QT_TRANSLATE_NOOP("bitcoin-core", "Staking Only - No active beacon"),
QT_TRANSLATE_NOOP("bitcoin-core", "Staking Only - Pool Detected"),
QT_TRANSLATE_NOOP("bitcoin-core", "Superblock Binary Size"),
QT_TRANSLATE_NOOP("bitcoin-core", "Testnet-only version"),
QT_TRANSLATE_NOOP("bitcoin-core", "The wallet is now shutting down. Please restart your wallet."),
QT_TRANSLATE_NOOP("bitcoin-core", "The wallet will now shutdown."),
QT_TRANSLATE_NOOP("bitcoin-core", "This update is "),
QT_TRANSLATE_NOOP("bitcoin-core", "To use the %s option"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unable to bind to %s on this computer (bind returned error %d, %s)"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown error"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown network specified in -onlynet: '%s'"),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown poll response type."),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown poll type."),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown poll weight type."),
QT_TRANSLATE_NOOP("bitcoin-core", "Unknown"),
QT_TRANSLATE_NOOP("bitcoin-core", "Usage:"),
QT_TRANSLATE_NOOP("bitcoin-core", "Verifying checkpoints..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Verifying database integrity..."),
QT_TRANSLATE_NOOP("bitcoin-core", "Vote signature failed. See debug.log."),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet %s resides outside data directory %s."),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet locked"),
QT_TRANSLATE_NOOP("bitcoin-core", "Wallet needed to be rewritten: restart Gridcoin to complete"),
QT_TRANSLATE_NOOP("bitcoin-core", "Warning: Disk space is low!"),
QT_TRANSLATE_NOOP("bitcoin-core", "Yes/No/Abstain"),
QT_TRANSLATE_NOOP("bitcoin-core", "You will need to delete the following."),
QT_TRANSLATE_NOOP("bitcoin-core", "\"%s\" is not a valid poll choice."),
QT_TRANSLATE_NOOP("bitcoin-core", "leisure"),
QT_TRANSLATE_NOOP("bitcoin-core", "mandatory"),
QT_TRANSLATE_NOOP("bitcoin-core", "unknown"),
QT_TRANSLATE_NOOP("bitcoin-core", "wallet.dat corrupt, salvage failed"),
};
